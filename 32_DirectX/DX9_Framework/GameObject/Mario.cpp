#include "Framework.h"
#include "Mario.h"

Mario::Mario()
	:state(IDLE), speed(100.0f), jumpSpeed(0), isRight(true), isJump(false), isPlayer(true), color(1.0f, 1.0f, 1.0f, 1.0f), passIndex(0)
{
	pos = { WIN_CENTER_X, WIN_CENTER_Y };

	SetAnimation();

	SetWeapon();

	collider = new ColliderBox({ 50, 50 }, this);
	collider->HitEvent() = bind(&Mario::Damage, this);
	collider->IsActive() = true;

	//
	rainbow = TEXTURE->Add(L"Textures/rainbow.png");

	 marioShader = Shader::Add(L"MultiShader");
	//weaponShader = Shader::Add(L"AlphaShader");
	weaponShader = Shader::Add(L"OutlineShader");

	TwBar* bar = TweakBar::Get()->GetBar();
	TwAddVarRW(bar, "Color"    , TW_TYPE_COLOR4F, &color, "");
	TwAddVarRW(bar, "PassIndex", TW_TYPE_INT32  , &passIndex, "");
	TwAddVarRW(bar, "Weight"   , TW_TYPE_INT32  , &weight, "");
}

Mario::~Mario()
{
	for (Animation* action : actions)
		delete action;

	delete collider;
}

void Mario::Update()
{
	Move();
	SetWeapon();

	UpdateWorld();
	actions[state]->Update();

	collider->Update();
}

void Mario::Render()
{
	SetWorld();

	marioShader->SetTexture( "srcMap", actions[state]->GetCurAction()->GetTexture());
	marioShader->SetTexture("destMap", rainbow->GetTexture());

	Vector2 uvStart = actions[state]->GetCurAction()->GetUVStart();
	Vector2 uvEnd   = actions[state]->GetCurAction()->GetUVEnd  ();

	marioShader->SetArray("uvStart", &uvStart, 2);
	marioShader->SetArray("uvEnd"  , &uvEnd  , 2);

	marioShader->Begin(passIndex);

	actions[state]->Render();

	marioShader->End();

	weaponTrans.SetWorld();

	Vector2 imageSize = weaponTex->GetImageSize();
	weaponShader->SetArray("Color", &color, 4);
	weaponShader->SetArray("ImageSize", &imageSize, 2);
	weaponShader->SetInt("Weight", weight);
	weaponShader->Begin();

	weaponTex->Render();

	weaponShader->End();

	collider->Render();
}

void Mario::Move()
{
	if (!isPlayer)
		return;

	if (KEYPRESS(VK_LEFT))
	{
		pos += V_LEFT  * speed * Time::Delta();

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
		SetAction(IDLE);
}

void Mario::SetWeapon()
{
	if (!isPlayer)
		return;

	weaponTrans.pos = this->pos;

	Vector2 dir = mousePos - this->pos;

	weaponTrans.angle = atan2(dir.y, dir.x) + (0.75f * PI);

	if (KEYDOWN(VK_LBUTTON))
		int a = 0;

	weaponTrans.UpdateWorld();
}


void Mario::SetAnimation()
{
	//IDLE
	vector<Texture*> frames;
	frames.push_back(TEXTURE->Add(L"Textures/mario_all.png", 8, 4, 1, 3));
	frames.push_back(TEXTURE->Add(L"Textures/mario_all.png", 8, 4, 2, 3));
	frames.push_back(TEXTURE->Add(L"Textures/mario_all.png", 8, 4, 5, 3));

	actions.push_back(new Animation(frames));

	frames.clear();

	//MOVE
	frames.push_back(TEXTURE->Add(L"Textures/mario_all.png", 8, 4, 1, 1));
	frames.push_back(TEXTURE->Add(L"Textures/mario_all.png", 8, 4, 2, 1));
	frames.push_back(TEXTURE->Add(L"Textures/mario_all.png", 8, 4, 3, 1));

	actions.push_back(new Animation(frames));

	frames.clear();

	//JUMP
	frames.push_back(TEXTURE->Add(L"Textures/mario_all.png", 8, 4, 2, 0));
	frames.push_back(TEXTURE->Add(L"Textures/mario_all.png", 8, 4, 3, 0));

	actions.push_back(new Animation(frames, END, 0.3f));

	frames.clear();

	actions[state]->Play();


	//Weapon
	weaponTex = TEXTURE->Add(L"Textures/Items.png", 10, 10, 1, 1, Vector2(1.0f, 1.0f));
	weaponTrans.scale = { 3, 3 };
}

void Mario::SetAction(State state)
{
	if (this->state == state)
		return;

	this->state = state;
	actions[state]->Play();
}

void Mario::Damage()
{
	state = RUN;
	actions[state]->Play();
}

