#include "Framework.h"
#include "BulletManager.h"

BulletManager* BulletManager::instance = nullptr;

BulletManager::BulletManager()
{
	bulletImg  = TextureManager::Get()->AddTexture("Bullet", L"Textures/Bullet.png", 2, 2);
	destroyImg = TextureManager::Get()->AddTexture("BulletDestroy", L"Textures/Explosion.png", 5, 1);

	for (UINT i = 0; i < 10; i++)
	{
		playerBullet.push_back(new PlayerBullet(bulletImg, destroyImg));
	}

	for (UINT i = 0; i < 100; i++)
	{
		enemyBullet.push_back(new EnemyBullet(bulletImg, destroyImg));
	}
}

BulletManager::~BulletManager()
{
	for (auto& bullet : playerBullet)
	{
		delete bullet;
	}

	for (auto& bullet : enemyBullet)
	{
		delete bullet;
	}

	playerBullet.clear();
	enemyBullet.clear();
}

void BulletManager::Update()
{
	for (auto& bullet : playerBullet)
	{
		bullet->Update();
	}
	for (auto& bullet : enemyBullet)
	{
		bullet->Update();
	}
}

void BulletManager::Render(HDC hdc)
{
	for (auto& bullet : playerBullet)
	{
		bullet->Render(hdc);
	}
	for (auto& bullet : enemyBullet)
	{
		bullet->Render(hdc);
	}
}

void BulletManager::PlayerFire(Vector2 pos, Vector2 dir)
{
	for (auto& bullet : playerBullet)
	{
		if (!bullet->IsUse())
		{
			bullet->Fire(pos, dir);
			return;
		}
	}
}

void BulletManager::EnemyFire(Vector2 pos, Vector2 dir)
{
	for (auto& bullet : enemyBullet)
	{
		if (!bullet->IsUse())
		{
			bullet->Fire(pos, dir);
			return;
		}
	}
}

