#include "Framework.h"
#include "AKStageManager.h"

AKStageManager::AKStageManager(AKUI* _ui)
	: ui(_ui)
	, stage(0)
{
	for (int i = 0; i < BRICKXCOUNT * BRICKYCOUNT; i++)
	{
		AKBrick* brick = new AKBrick();
		bricks.push_back(brick);
	}

	initStage();
	StageChange();
}

AKStageManager::~AKStageManager()
{
	for (AKBrick* brick : bricks)
		delete brick;

	bricks.clear();
}

void AKStageManager::Update()
{
}

void AKStageManager::Render(HDC hdc)
{
	for (auto& brick : bricks)
	{
		brick->Render(hdc);
	}
}

bool AKStageManager::IsStageClear()
{
	for (AKBrick* brick : bricks)
	{
		if (brick->GetHp() > 0)
		{
			return false;
		}
	}
	return true;
}

bool AKStageManager::NextStage()
{
	if (stage >= maps.size() - 1)
		return false;
	
	++stage;
	StageChange();

	return true;
}

void AKStageManager::initStage()
{
	vector<vector<int>> map0 =
	{
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
	};
	maps.push_back(map0);

	vector<vector<int>> map1 =
	{
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 1, 0, 0, 2, 2, 0, 0, 1, 0, 0},
		{0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 1, 0, 3, 0, 1, 1, 0, 3, 0, 1, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
	};
	maps.push_back(map1);

	vector<vector<int>> map2 =
	{
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 0},
		{0, 4, 2, 1, 1, 3, 3, 1, 1, 2, 4, 0},
		{0, 4, 1, 1, 1, 2, 2, 1, 1, 1, 4, 0},
		{0, 4, 1, 1, 1, 1, 1, 1, 1, 1, 4, 0},
		{0, 4, 1, 1, 1, 1, 1, 1, 1, 1, 4, 0},
		{0, 4, 1, 1, 1, 1, 1, 1, 1, 1, 4, 0},
		{0, 4, 2, 1, 1, 1, 1, 1, 1, 2, 4, 0},
		{0, 4, 3, 2, 1, 1, 1, 1, 2, 3, 4, 0},
		{0, 4, 0, 3, 2, 1, 1, 2, 3, 0, 4, 0},
		{0, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
	};
	maps.push_back(map2);
}

void AKStageManager::StageChange()
{
	for (auto& brick : bricks)
	{
		brick->ResetBrick();
	}

	for (size_t y = 0; y < maps[stage].size(); y++)
	{
		for (size_t x = 0; x < maps[stage][y].size(); x++)
		{
			if (maps[stage][y][x] == 0)
				continue;

			for (auto& brick : bricks)
			{
				if (!brick->isUse)
				{
					brick->isUse = true;
					brick->SetHp(maps[stage][y][x]);
					brick->GetRect()->Pos().x = (x * BRICK_WIDTH) + (BRICK_WIDTH / 2) + ui->GetStageLeft();
					brick->GetRect()->Pos().y = (y * BRICK_HEIGHT) + (BRICK_HEIGHT / 2) + ui->GetStageTop();
					brick->GetRect()->Size() = Vector2(BRICK_WIDTH, BRICK_HEIGHT);
					break;
				}
			}
		}
	}
}
