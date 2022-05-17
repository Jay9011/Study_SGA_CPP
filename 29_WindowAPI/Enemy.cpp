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
}

Enemy::~Enemy()
{
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
		dir.x *= -1;
		time = 0;
		randomTime = Math::Random(10.0, 15.0);
	}
}

void Enemy::Render()
{
	if (!isActive)
		return;

	texture->Render(rect, frame);
}
