#include "Framework.h"
#include "Missile.h"

Missile::Missile()
	: Object(TextureManager::Get()->AddTexture("Missile", L"Textures/missilePF.png", 16, 1))
	, speed(300)
{
	animation = new Animation(texture);
	animation->SetDefault(true);
	animation->Play();
}

Missile::~Missile()
{
	delete animation;
}

void Missile::Update()
{
	Vector2 tmpPos = rect->Pos();
	if (KEY_PRESS(VK_LEFT))
	{
		rect->Pos() += V_LEFT  * speed * Time::Delta();
	}
	if (KEY_PRESS(VK_RIGHT))
	{
		rect->Pos() += V_RIGHT * speed * Time::Delta();
	}
	if (KEY_PRESS(VK_UP))
	{
		rect->Pos() += V_UP    * speed * Time::Delta();
	}
	if (KEY_PRESS(VK_DOWN))
	{
		rect->Pos() += V_DOWN  * speed * Time::Delta();
	}

	if (tmpPos != rect->Pos())
	{
		angle = Math::RadianToDegree((tmpPos - rect->Pos()).Normalize().VectorToAngle()) + 180;
	}


	animation->Update();
}

void Missile::Render()
{
	wstring str = to_wstring(angle);
	TextOut(backDC, 0, 40, str.c_str(), str.size());
	
	Object::Render({ ((int)angle / 22) % 16, 0 }, Camera::Get()->Pos());
	//Object::Render(animation->GetFrame(), Camera::Get()->Pos());
}
