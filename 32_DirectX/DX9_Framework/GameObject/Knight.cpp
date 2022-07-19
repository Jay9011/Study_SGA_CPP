#include "Framework.h"
#include "Knight.h"

Knight::Knight()
	:speed(100), isRight(true), isAttacking(false), state(IDLE)
{
	pos   = { WIN_CENTER_X, WIN_CENTER_Y };
	scale = { 0.3f, 0.3f };

	LoadXML("Knight_Idle.xml",   LOOP);
	LoadXML("Knight_Walk.xml",   LOOP);
	LoadXML("Knight_Attack.xml", END);

	actions[ATTACK]->SetEndEvent(bind(&Knight::EndAttack, this));

	actions[state]->Play();

	weaponCollider = new ColliderBox({ 150, 150 }, this);
	weaponOffset = { 40, 0 };

	weaponCollider->SetOffset(weaponOffset);

	shader = Shader::Add(L"ObjectShader");
}

Knight::~Knight()
{
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

	weaponCollider->Update();
}

void Knight::Render()
{
	SetWorld();
	shader->Begin();
	actions[state]->Render();
	shader->End();

	weaponCollider->Render();
}

void Knight::Move()
{
	if (isAttacking)
		return;

	if (KEYPRESS(VK_LEFT))
	{
		pos += V_LEFT  * speed * Time::Delta();

		if (isRight)
		{
			isRight = !isRight;

			scale.x *= -1;
		}

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

		SetAction(WALK);
	}

	if (KEYUP(VK_LEFT) || KEYUP(VK_RIGHT))
		SetAction(IDLE);
}

void Knight::Attack()
{
	if (KEYDOWN(VK_SPACE))
	{
		SetAction(ATTACK);

		isAttacking = true;

		weaponCollider->IsActive() = true;

		//TODO: Weapon 방향 설정, Offset 설정
		if (isRight)
		{
			weaponOffset.x = 40;
		}
		else
		{
			weaponOffset.x = -40;
		}

		weaponCollider->SetOffset(weaponOffset);
		weaponCollider->Update();
	}

	//TODO: Enemy Collision시 HitEvent 호출
	for (Collider* enemy : enemies)
	{
		if (weaponCollider->Collision(enemy))
			enemy->hitEvent();
	}
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
		Vector2 start = { sprite->FloatAttribute("x"),  sprite->FloatAttribute("y")  };
		Vector2   end = { sprite->FloatAttribute("w"),  sprite->FloatAttribute("h")  };
		Vector2 pivot = { sprite->FloatAttribute("pX"), sprite->FloatAttribute("pY") };

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

void Knight::EndAttack()
{
	isAttacking = false;

	SetAction(IDLE);

	weaponCollider->IsActive() = false;
}
