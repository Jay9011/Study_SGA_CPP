#include "Framework.h"
#include "EnemyManager.h"

EnemyManager::EnemyManager(UINT _count)
	: time(0)
	, randomTime(0)
{
	Texture* texture = TextureManager::Get()->AddTexture("Enemy", L"Textures/ufo.png", 10, 1);

	for (UINT i = 0; i < _count; i++)
	{
		Vector2 pos;
		pos.x = Math::Random(texture->GetFrameSize().x, WIN_WIDTH - texture->GetFrameSize().x);
		pos.y = -(texture->GetFrameSize().y);

		enemies.push_back(new Enemy(pos));
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
	
	++time;
	if (time > randomTime)
	{
		SpawnEnemy();
		time = 0;
		randomTime = Math::Random(10.0, 30.0);
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
			enemy->IsActive() = true;

			break;
		}
	}
}
