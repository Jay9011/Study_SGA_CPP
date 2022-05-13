#include "Framework.h"
#include "BulletManager.h"

BulletManager* BulletManager::instance = nullptr;

BulletManager::BulletManager()
{
	bulletImg = TextureManager::Get()->AddTexture("Bullet", L"Textures/Bullet.png", 2, 2);

	for (UINT i = 0; i < 10; i++)
	{
		playerBullet.push_back(new PlayerBullet(bulletImg));
	}

	OutputDebugString(L"BulletManager »ý¼º\n");
}

BulletManager::~BulletManager()
{
	for (auto& bullet : playerBullet)
	{
		delete bullet;
	}

	playerBullet.clear();
	enemyBullet.clear();

	OutputDebugString(L"BulletManager ¼Ò¸ê\n");
}

void BulletManager::Update()
{
	for (auto& bullet : playerBullet)
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
}

