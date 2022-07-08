#include "Framework.h"
#include "Knight.h"

Knight::Knight() : 
	speed(100), isRight(true), isAttacking(false), state(IDLE)
{
	pos = { WIN_CENTER_X, WIN_CENTER_Y };
	scale = { .3f, .3f };

	LoadXML("Knight_IDLE.xml", LOOP);
	LoadXML("Knight_Walk.xml", LOOP);
	LoadXML("Knight_Attack.xml", END);
	actions[ATTACK]->SetEndEvent(bind(&Knight::EndAttack, this));

	actions[state]->Play();

	weaponCollider = new ColliderBox({ 100, 150 }, this);
	weaponCollider->SetOffset(weaponOffset);
}

Knight::~Knight()
{
	delete weaponCollider;

	for (Animation* action : actions)
		delete action;

	actions.clear();
}

void Knight::Update()
{
	Move();
	Attack();

	actions[state]->Update();
	UpdateWorld();
}

void Knight::Render()
{
	SetWorld();
	actions[state]->Render();
}

void Knight::Move()
{
	if (KEYPRESS(VK_LEFT))
	{
		pos += V_LEFT * speed * Time::Delta();

		if (isRight)
		{
			isRight = !isRight;

			scale.x *= -1;
		}

		if (!isAttacking)
			SetAction(WALK);
	}
	if (KEYPRESS(VK_RIGHT))
	{
		pos += V_RIGHT * speed * Time::Delta();

		if (!isRight)
		{
			isRight = !isRight;

			scale.x *= -1;
		}
		if (!isAttacking)
			SetAction(WALK);
	}
	if (KEYUP(VK_LEFT) || KEYUP(VK_RIGHT))
	{
		if (!isAttacking)
			SetAction(IDLE);
	}
}

void Knight::Attack()
{
	if (KEYDOWN(VK_SPACE))
	{
		SetAction(ATTACK);
		isAttacking = true;
		weaponCollider->IsActive() = true;
	}
}

void Knight::EndAttack()
{
	isAttacking = false;

	SetAction(IDLE);
}

void Knight::LoadXML(string fileName, Type type, float speed)
{
	XmlDocument* document = new XmlDocument;

	document->LoadFile((knightPath + fileName).c_str());

	XmlElement* atlas = document->FirstChildElement();
	string imageName = atlas->Attribute("imagePath");

	imageName = knightPath + imageName;

	wstring imagePath;
	imagePath.assign(imageName.begin(), imageName.end());

	vector<Texture*> clips;

	XmlElement* sprite = atlas->FirstChildElement();

	while (sprite != nullptr)
	{
		D3DXVECTOR2 start = { sprite-> FloatAttribute("x"), sprite-> FloatAttribute("y") };
		D3DXVECTOR2 end   = { sprite-> FloatAttribute("w"), sprite-> FloatAttribute("h") };
		D3DXVECTOR2 pivot = { sprite-> FloatAttribute("pX"), sprite-> FloatAttribute("pY") };

		end += start;

		clips.push_back(TEXTURE->Add(imagePath, start, end, pivot));

		sprite = sprite->NextSiblingElement();
	}

	actions.push_back(new Animation(clips, type, speed));

	delete document;
}

void Knight::SetAction(State state)
{
	if (this->state == state)
		return;

	this->state = state;
	actions[state]->Play();
}
