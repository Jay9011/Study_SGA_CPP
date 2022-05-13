#include "Framework.h"
#include "EnemyManager.h"

EnemyManager* EnemyManager::instance = nullptr;

EnemyManager::EnemyManager()
	: timer(0)
	, maxTimer(100)
	, usableAPoint(0)
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

	for (UINT i = 0; i < arrivalPoint.size(); i++)
	{
		enemies.push_back(new Enemy());
	}
}

EnemyManager::~EnemyManager()
{
	for (Enemy* enemy : enemies)
	{
		delete enemy;
	}
	enemies.clear();

	for (PointFlag* point : spawnPoint)
	{
		delete point;
	}
	spawnPoint.clear();

	for (PointFlag* point : arrivalPoint)
	{
		delete point;
	}
	arrivalPoint.clear();
}

void EnemyManager::Update()
{
	EnemySpawn();

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
	if (timer < maxTimer)
	{
		++timer;
	}

	// Check spawn Timer
	int newTimer = maxTimer - (PlayerManager::Get()->player->GetScore() / 2);
	if (newTimer < 10)
		newTimer = 10;

	if (timer < newTimer)
		return;

	// Check usable Arrival Point
	usableAPoint = 0;
	for (PointFlag* point : arrivalPoint)
	{
		if (!point->isUse) 
			++usableAPoint;
	}
	
	if (usableAPoint > 1)
	{
		while (true)
		{
			int randNum = rand() % arrivalPoint.size();
			if (arrivalPoint[randNum]->isUse)
				continue;

			if (EnemySetting(arrivalPoint[randNum]))
			{
				timer = 0;
				return;
			}
		}
	}
	else if (usableAPoint == 1)
	{
		for (PointFlag* point : arrivalPoint)
		{
			if (point->isUse)
				continue;

			if (EnemySetting(point))
			{
				timer = 0;
				return;
			}
		}
	}
	
}

void EnemyManager::SetSpawnPoint()
{
	spawnPoint.push_back(new PointFlag{ false, {(WIN_WIDTH * 0.3), (-10)} });
	spawnPoint.push_back(new PointFlag{ false, {(WIN_WIDTH * 0.6), (-10)} });
	spawnPoint.push_back(new PointFlag{ false, {(WIN_WIDTH * 0.9), (-10)} });
	spawnPoint.push_back(new PointFlag{ false, {(WIN_WIDTH - 10.0) , (WIN_HEIGHT * 0.3) } });
	spawnPoint.push_back(new PointFlag{ false, {(WIN_WIDTH + 10.0) , (WIN_HEIGHT * 0.3) } });
}

void EnemyManager::SetArrivalPoint()
{
	arrivalPoint.push_back(new PointFlag{ false, {(WIN_WIDTH * 0.3), (WIN_HEIGHT * 0.1)} });
	arrivalPoint.push_back(new PointFlag{ false, {(WIN_WIDTH * 0.5), (WIN_HEIGHT * 0.1)} });
	arrivalPoint.push_back(new PointFlag{ false, {(WIN_WIDTH * 0.7), (WIN_HEIGHT * 0.1)} });

	arrivalPoint.push_back(new PointFlag{ false, {(WIN_WIDTH * 0.2), (WIN_HEIGHT * 0.2)} });
	arrivalPoint.push_back(new PointFlag{ false, {(WIN_WIDTH * 0.4), (WIN_HEIGHT * 0.2)} });
	arrivalPoint.push_back(new PointFlag{ false, {(WIN_WIDTH * 0.6), (WIN_HEIGHT * 0.2)} });
	arrivalPoint.push_back(new PointFlag{ false, {(WIN_WIDTH * 0.8), (WIN_HEIGHT * 0.2)} });
	
	arrivalPoint.push_back(new PointFlag{ false, {(WIN_WIDTH * 0.3), (WIN_HEIGHT * 0.3)} });
	arrivalPoint.push_back(new PointFlag{ false, {(WIN_WIDTH * 0.5), (WIN_HEIGHT * 0.3)} });
	arrivalPoint.push_back(new PointFlag{ false, {(WIN_WIDTH * 0.7), (WIN_HEIGHT * 0.3)} });
}

bool EnemyManager::EnemySetting(PointFlag* point)
{
	int typeNum = rand() % (int)ENEMY_TYPE::END;
	ENEMY_TYPE type = (ENEMY_TYPE)typeNum;

	int spawnNum = rand() % spawnPoint.size();
	PointFlag* spawn = spawnPoint[spawnNum];

	for (Enemy* enemy : enemies)
	{
		if (enemy->GetType() != ENEMY_TYPE::END)
			continue;

		enemy->Setting(type, enemyImg[typeNum], spawn, point);
		return true;
	}

	return false;
}
