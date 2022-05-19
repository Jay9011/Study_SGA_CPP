#include "Framework.h"
#include "BulletManager.h"

BulletManager::BulletManager()
{
	UINT poolCount = 30;

	for (UINT i = 0; i < poolCount; i++)
	{
		bullets.push_back(new Bullet);
	}
}

BulletManager::~BulletManager()
{
	for (Bullet* bullet : bullets)
	{
		delete bullet;
	}

	bullets.clear();
}

void BulletManager::Update()
{
	for (Bullet* bullet : bullets)
	{
		bullet->Update();
	}
}

void BulletManager::Render()
{
	for (Bullet* bullet : bullets)
	{
		bullet->Render();
	}
}

void BulletManager::Fire(Vector2 _pos, Vector2 _dir, double _speed)
{
	for (Bullet* bullet : bullets)
	{
		if (!bullet->IsFire())
		{
			bullet->Fire(_pos, _dir, _speed);
			return;
		}
	}
}
