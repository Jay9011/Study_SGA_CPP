#include "Framework.h"
#include "Enemy.h"

Enemy::Enemy()
	: speed(10)
	, frame({0, 0})
	, isActive(false)
	, time(0)
	, randomTime(0)
{
	texture = TextureManager::Get()->AddTexture("Enemy", L"Textures/ufo.png", 10, 1);

	bool random = rand() % 2;
	if (random)
		dir = V_LDOWN;
	else
		dir = V_RDOWN;

	rect = new Rect({ WIN_CENTER_X, WIN_CENTER_Y * 0.1 }, texture->GetFrameSize());

	bullets = new BulletManager;
}

Enemy::Enemy(Vector2 _pos)
	: speed(10)
	, frame({ 0, 0 })
	, isActive(false)
	, time(0)
	, randomTime(0)
{
	texture = TextureManager::Get()->AddTexture("Enemy", L"Textures/ufo.png", 10, 1);

	bool random = rand() % 2;
	if (random)
		dir = V_LDOWN;
	else
		dir = V_RDOWN;

	rect = new Rect(_pos, texture->GetFrameSize());

	bullets = new BulletManager;
}

Enemy::~Enemy()
{
	delete bullets;
	delete rect;
}

void Enemy::Update()
{
	if (!isActive)
		return;

	++frame.x %= texture->GetMaxFrame().x;

	rect->Pos() += dir * speed;

	++time;
	if (time > randomTime)
	{
		Shoot();
		Move();
	}

	bullets->Update();
}

void Enemy::Render()
{
	if (!isActive)
		return;

	texture->Render(rect, frame);
	bullets->Render();
}

void Enemy::Move()
{
	dir.x *= -1;
	time = 0;
	randomTime = Math::Random(10.0, 15.0);
}

void Enemy::Shoot()
{
	if (time> randomTime)
	{
		bullets->Fire(Vector2(rect->Pos().x, rect->Bottom()), V_DOWN, 10);
	}
}

void Enemy::Collision(Plane* player)
{
	if (!isActive)
		return;

	for (Bullet* bullet : player->GetBulletManager()->GetBullets())
	{
		if (Collision::Collision(rect, bullet->GetRect()))
		{
			  this->isActive = false;
			bullet->IsFire() = false;

			return;
		}
	}
}
