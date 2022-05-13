#include "Framework.h"
#include "EnemyManager.h"

EnemyManager::EnemyManager()
{
	SetSpawnPoint();
	SetArrivalPoint();

	for (UINT i = 0; i < (UINT)ENEMY_TYPE::END; i++)
	{
		switch ((ENEMY_TYPE)i)
		{
		case ENEMY_TYPE::S:
			enemyImg[i] = TextureManager::Get()->AddTexture("EnemyS", L"Textures/EnemyS.png", 2, 1);
			break;
		case ENEMY_TYPE::M:
			enemyImg[i] = TextureManager::Get()->AddTexture("EnemyM", L"Textures/EnemyM.png", 2, 1);
			break;
		case ENEMY_TYPE::L:
			enemyImg[i] = TextureManager::Get()->AddTexture("EnemyL", L"Textures/EnemyL.png", 2, 1);
			break;
		default:
			break;
		}
	}

	for (UINT i = 0; i < 5; i++)
	{
		enemies.push_back(new Enemy());
	}

	// Debug
	OutputDebugString(L"EnemyManager »ý¼º\n");
}

EnemyManager::~EnemyManager()
{
	for (Enemy* enemy : enemies)
	{
		delete enemy;
	}
	enemies.clear();

	// Debug
	OutputDebugString(L"EnemyManager ¼Ò¸ê\n");
}

void EnemyManager::Update()
{
	// Enemy Update
	for (Enemy* enemy : enemies)
	{
		enemy->Update();
	}
}

void EnemyManager::Render(HDC hdc)
{
	for (Enemy* enemy : enemies)
	{
		enemy->Render(hdc);
	}
}

void EnemyManager::EnemySpawn()
{
	// Spawn Timer
	++timer;
	if (timer > 30)
	{
		timer = 0;
		int typeNum = rand() % (int)ENEMY_TYPE::END;
		ENEMY_TYPE type = (ENEMY_TYPE)typeNum;

		for (Enemy* enemy : enemies)
		{
			if (enemy->GetType() != ENEMY_TYPE::END)
				continue;
			
			enemy->Setting(type, enemyImg[typeNum]);
			break;
		}
	}
}

void EnemyManager::SetSpawnPoint()
{
	spawnPoint.push_back({ false, {(LONG)(WIN_WIDTH * 0.3), (-10)} });
	spawnPoint.push_back({ false, {(LONG)(WIN_WIDTH * 0.6), (-10)} });
	spawnPoint.push_back({ false, {(LONG)(WIN_WIDTH * 0.9), (-10)} });
	spawnPoint.push_back({ false, {WIN_WIDTH - 10 , (LONG)(WIN_HEIGHT * 0.3) } });
	spawnPoint.push_back({ false, {WIN_WIDTH + 10 , (LONG)(WIN_HEIGHT * 0.3) } });
}

void EnemyManager::SetArrivalPoint()
{
	arrivalPoint.push_back({ false, {(LONG)(WIN_WIDTH * 0.3), (LONG)(WIN_HEIGHT * 0.1)} });
	arrivalPoint.push_back({ false, {(LONG)(WIN_WIDTH * 0.6), (LONG)(WIN_HEIGHT * 0.1)} });
	arrivalPoint.push_back({ false, {(LONG)(WIN_WIDTH * 0.9), (LONG)(WIN_HEIGHT * 0.1)} });

	arrivalPoint.push_back({ false, {(LONG)(WIN_WIDTH * 0.2), (LONG)(WIN_HEIGHT * 0.2)} });
	arrivalPoint.push_back({ false, {(LONG)(WIN_WIDTH * 0.4), (LONG)(WIN_HEIGHT * 0.2)} });
	arrivalPoint.push_back({ false, {(LONG)(WIN_WIDTH * 0.6), (LONG)(WIN_HEIGHT * 0.2)} });
	arrivalPoint.push_back({ false, {(LONG)(WIN_WIDTH * 0.8), (LONG)(WIN_HEIGHT * 0.2)} });
	
	arrivalPoint.push_back({ false, {(LONG)(WIN_WIDTH * 0.3), (LONG)(WIN_HEIGHT * 0.3)} });
	arrivalPoint.push_back({ false, {(LONG)(WIN_WIDTH * 0.6), (LONG)(WIN_HEIGHT * 0.3)} });
	arrivalPoint.push_back({ false, {(LONG)(WIN_WIDTH * 0.9), (LONG)(WIN_HEIGHT * 0.3)} });
}
