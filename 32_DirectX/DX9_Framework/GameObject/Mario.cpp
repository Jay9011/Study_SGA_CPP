#include "Framework.h"
#include "Mario.h"

Mario::Mario() :
	state(IDLE), speed(100.f), jumpSpeed(0), isRight(true), isJump(false), isPlayer(false), isDamagedAnimPlay(false)
{
	pos = { WIN_CENTER_X, WIN_CENTER_Y };

	SetAnimation();
	actions[state]->Play();

	SetWeapon();

	collider = new ColliderBox({ 50, 50 }, this);
	collider->HitEvent() = bind(&Mario::Damage, this);
}

Mario::~Mario()
{
	delete collider;

	for (Animation* action : actions)
	{
		delete action;
	}
}

void Mario::Update()
{
	Move();
	SetWeapon();

	actions[state]->Update();
	UpdateWorld();

	collider->Update();
}

void Mario::Render()
{
	SetWorld();
	actions[state]->Render();

	weaponTrans.SetWorld();
	weaponTexture->Render();

	collider->Render();
}

void Mario::Move()
{
	if (!isPlayer)
		return;

	if (KEYPRESS(VK_LEFT))
	{
		pos += V_LEFT * speed * Time::Delta();

		if (isRight)
		{
			isRight = !isRight;

			scale.x *= -1;
		}
		
		SetAction(RUN);
	}
	if (KEYPRESS(VK_RIGHT))
	{
		pos += V_RIGHT * speed * Time::Delta();

		if (!isRight)
		{
			isRight = !isRight;

			scale.x *= -1;
		}

		SetAction(RUN);
	}
	if (KEYUP(VK_LEFT) || KEYUP(VK_RIGHT))
	{
		SetAction(IDLE);
	}
}

void Mario::SetWeapon()
{
	if (!isPlayer)
		return;

	weaponTrans.pos = this->pos;

	D3DXVECTOR2 dir = mousePos - this->pos;
	weaponTrans.angle = atan2(dir.y, dir.x) + (PI * 0.75);
	
	weaponTrans.UpdateWorld();
}

void Mario::Damage()
{
	if (isDamagedAnimPlay)
		return;

	actions[JUMP]->SetEndEvent([this]() {SetAction(IDLE); isDamagedAnimPlay = false; });
	SetAction(JUMP);
	isDamagedAnimPlay = true;
}

void Mario::SetAnimation()
{
	vector<Texture*> frames;

	// IDEL
	frames.push_back(TEXTURE->Add(L"Textures/mario_all.png", 8, 4, 1, 3));
	frames.push_back(TEXTURE->Add(L"Textures/mario_all.png", 8, 4, 2, 3));
	frames.push_back(TEXTURE->Add(L"Textures/mario_all.png", 8, 4, 5, 3));

	actions.push_back(new Animation(frames));
	frames.clear();

	// MOVE
	frames.push_back(TEXTURE->Add(L"Textures/mario_all.png", 8, 4, 1, 1));
	frames.push_back(TEXTURE->Add(L"Textures/mario_all.png", 8, 4, 2, 1));
	frames.push_back(TEXTURE->Add(L"Textures/mario_all.png", 8, 4, 3, 1));

	actions.push_back(new Animation(frames));
	frames.clear();

	// JUMP
	frames.push_back(TEXTURE->Add(L"Textures/mario_all.png", 8, 4, 2, 0));
	frames.push_back(TEXTURE->Add(L"Textures/mario_all.png", 8, 4, 3, 0));

	actions.push_back(new Animation(frames, END, 0.3f));
	frames.clear();



	// Weapon
	weaponTexture = TEXTURE->Add(L"Textures/Items.png", 10, 10, 1, 1, D3DXVECTOR2(1.f, 1.f));
	weaponTrans.scale = { 2, 2 };
}

void Mario::SetAction(State state)
{
	if (this->state == state)
		return;

	this->state = state;
	actions[state]->Play();
}
