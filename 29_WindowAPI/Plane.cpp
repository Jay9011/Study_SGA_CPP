#include "Framework.h"
#include "Plane.h"

Plane::Plane()
	: speed(200)
	, hp(3)
	, dead(false)
{
	texture = TextureManager::Get()->AddTexture("Plane", L"Textures/airplane.png");

	rect = new Rect({ WIN_CENTER_X, WIN_HEIGHT * 0.8 }, { 100, 100 });

	bullets = new BulletManager;
}

Plane::~Plane()
{
	delete rect;
	delete bullets;
}

void Plane::Update()
{
	if (dead)
		return;

	Move();
	Shoot();
	bullets->Update();
}

void Plane::Render()
{
	if (dead)
		return;
	
	texture->Render(rect);
	bullets->Render();
}

void Plane::Move()
{
	if (KEY_PRESS(VK_LEFT))
	{
		rect->Pos() += V_LEFT * speed * Time::Delta();
	}
	if (KEY_PRESS(VK_RIGHT))
	{
		rect->Pos() += V_RIGHT * speed * Time::Delta();
	}

	if (KEY_PRESS(VK_UP))
	{
		rect->Pos() += V_UP * speed * Time::Delta();
	}
	if (KEY_PRESS(VK_DOWN))
	{
		rect->Pos() += V_DOWN * speed * Time::Delta();
	}
}

void Plane::Shoot()
{
	if (KEY_DOWN(VK_SPACE))
	{
		bullets->Fire(Vector2(rect->Pos().x, rect->Top()), V_UP, 400);
	}
}

void Plane::Collision(EnemyManager* enemies)
{
	if (dead)
		return;

	for (Enemy* enemy : enemies->GetEnemies())
	{
		if (enemy->IsActive())
		{
			// Enemy vs Plane
			if (Collision::Collision(this->rect, enemy->GetRect()))
			{
				enemy->IsActive() = false;
			}

			// EnemyBullet vs Plane
			for (Bullet* bullet : enemy->GetBulletManager()->GetBullets())
			{
				if (Collision::Collision(rect, bullet->GetRect()))
				{
					if (!bullet->IsFire())
						return;

					--hp;
					bullet->IsFire() = false;

					if (hp <= 0)
					{
						dead = true;
					}

					break;
				}
			}
		}
	}
}
