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
	time += Time::Delta();

	bullets->Update();

	if (!isActive)
		return;

	++frame.x %= texture->GetMaxFrame().x;
	
	Move();

	if (time > randomTime)
	{
		Shoot();
		ChangeDirection();
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
	rect->Pos() += dir * speed * Time::Delta();

	if (rect->Top() > WIN_HEIGHT)
	{
		isActive = false;
	}
}

void Enemy::ChangeDirection()
{
	dir.x *= -1;
	time = 0;
	randomTime = Math::Random(0.5, 1.0);
}

void Enemy::Shoot()
{
	if (time > randomTime)
	{
		bullets->Fire(Vector2(rect->Pos().x, rect->Bottom()), targetDir, 300);
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

void Enemy::SetTarget(Plane* player)
{
	for (Bullet* bullet : bullets->GetBullets())
	{
		targetDir = (player->GetRect()->Pos() - bullet->GetRect()->Pos()).Normal();
		bullet->SetDir(targetDir);
	}
}

void Enemy::GetPlayer(Plane* player)
{
	SetTarget(player);
	Collision(player);
}