#include "Framework.h"
#include "Enemy.h"

Enemy::Enemy()
	: speed(100)
	, hp(0)
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
	: speed(100)
	, hp(0)
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
	bullets->Update();

	if (!isActive)
		return;

	++frame.x %= texture->GetMaxFrame().x;

	rect->Pos() += dir * speed * Time::Delta();

	time += Time::Delta();

	if (time > randomTime)
	{
		Shoot();
		Move();
	}
}

void Enemy::Render()
{
	bullets->Render();

	if (!isActive)
		return;

	texture->Render(rect, frame);
}

void Enemy::Move()
{
	dir.x *= -1;
	time = 0;
	randomTime = Math::Random(1.0, 2.0);
}

void Enemy::Shoot()
{
	if (time > randomTime)
	{
		bullets->Fire(Vector2(rect->Pos().x, rect->Bottom()), (player->GetRect()->Pos() - rect->Pos()).Normalize(), 300);
	}
}

void Enemy::SetPlayer(Plane* player)
{
	this->player = player;
}

void Enemy::Collision(Plane* player)
{
	if (!isActive)
		return;

	for (Bullet* bullet : player->GetBulletManager()->GetBullets())
	{
		if (Collision::Collision(rect, bullet->GetRect()))
		{
			if (!bullet->IsFire())
				return;

			--hp;
			bullet->IsFire() = false;

			if (hp <= 0)
			{
				  this->isActive = false;
			}

			return;
		}
	}
}
