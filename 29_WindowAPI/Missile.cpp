#include "Framework.h"
#include "Missile.h"

Missile::Missile()
	: Object(TextureManager::Get()->AddTexture("Missile", L"Textures/missilePF.png", 16, 1))
	, speed(500)
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
	animation->Update();

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
}

void Missile::Render()
{
	Object::Render(animation->GetFrame(), Camera::Get()->Pos());
}
