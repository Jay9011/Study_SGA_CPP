#include "Framework.h"
#include "Plane.h"

Plane::Plane()
	: speed(20)
{
	texture = TextureManager::Get()->AddTexture("Plane", L"Textures/airplane.png");

	rect = new Rect({ WIN_CENTER_X, WIN_HEIGHT * 0.8 }, { 100, 100 });
}

Plane::~Plane()
{
	delete rect;
}

void Plane::Update()
{
	Move();
}

void Plane::Render()
{
	texture->Render(rect);
}

void Plane::Move()
{
	if (KEY_PRESS(VK_LEFT))
	{
		rect->Pos() += V_LEFT * speed;
	}
	if (KEY_PRESS(VK_RIGHT))
	{
		rect->Pos() += V_RIGHT * speed;
	}

	if (KEY_PRESS(VK_UP))
	{
		rect->Pos() += V_UP * speed;
	}
	if (KEY_PRESS(VK_DOWN))
	{
		rect->Pos() += V_DOWN * speed;
	}
}

void Plane::Collision(EnemyManager* enemies)
{
	for (Enemy* enemy : enemies->GetEnemies())
	{
		if (enemy->IsActive())
		{
			if (Collision::Collision(this->rect, enemy->GetRect()))
			{
				enemy->IsActive() = false;
			}
		}
	}
}
