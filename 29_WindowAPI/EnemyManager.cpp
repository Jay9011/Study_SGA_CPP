#include "Framework.h"
#include "EnemyManager.h"

EnemyManager::EnemyManager(UINT _count)
	: time(0)
	, randomTime(0)
{
	Texture* texture = TextureManager::Get()->AddTexture("Enemy", L"Textures/ufo.png", 10, 1);

	for (UINT i = 0; i < _count; i++)
	{
		enemies.push_back(new Enemy());
	}
}

EnemyManager::~EnemyManager()
{
	for (Enemy* enemy : enemies)
		delete enemy;

	enemies.clear();
}

void EnemyManager::Update()
{
	for (Enemy* enemy : enemies)
	{
		enemy->Update();
	}
	
	time += Time::Delta();
	if (time > randomTime)
	{
		SpawnEnemy();
		time = 0;
		randomTime = Math::Random(1.0, 3.0);
	}
}

void EnemyManager::Render()
{
	for (Enemy* enemy : enemies)
	{
		enemy->Render();
	}
}

void EnemyManager::SpawnEnemy()
{
	for (Enemy* enemy : enemies)
	{
		if (!enemy->IsActive())
		{
			Vector2 pos;
			pos.x = Math::Random(enemy->GetRect()->Size().x, WIN_WIDTH - enemy->GetRect()->Size().x);
			pos.y = -(enemy->GetRect()->Size().y);

			enemy->GetRect()->Pos() = pos;
			enemy->SetHp(2);

			enemy->IsActive() = true;

			break;
		}
	}
}

void EnemyManager::GetPlayer(Plane* player)
{
	for (Enemy* enemy : enemies)
	{
		enemy->GetPlayer(player);
	}
}