#include "Framework.h"
#include "SGABrickManager.h"

SGABrickManager::SGABrickManager()
{
	CreateStage1();
}

SGABrickManager::~SGABrickManager()
{
}

void SGABrickManager::Render(HDC hdc)
{
	for (SGABrick* brick : bricks)
	{
		brick->Render(hdc);
	}
}

void SGABrickManager::CreateStage1()
{
	SGABrick* brick = new SGABrick(Vector2(WIN_CENTER_X, 100), Vector2(300, 100), 1);

	bricks.push_back(brick);
}

void SGABrickManager::CreateStage2()
{
	double numX = 10;
	double numY = 5;

	Vector2 size = { WIN_WIDTH / numX , WIN_HEIGHT * 0.5 / numY };

	for (UINT i = 0; i < numX; i++)
	{
		for (UINT j = 0; j < numY; j++)
		{
			Vector2 pos;
			pos.x = size.x * i + size.x * 0.5;
			pos.y = size.y * j + size.y * 0.5;

			SGABrick* brick = new SGABrick(pos, { size.x, size.y * 0.5 }, MAX_HP - j);
			bricks.push_back(brick);
		}
	}
}

void SGABrickManager::ClearStage()
{
	for (SGABrick* brick : bricks)
		delete brick;
	
	bricks.clear();
}

bool SGABrickManager::GetRemainBricks()
{
	UINT count = 0;

	for (SGABrick* brick : bricks)
	{
		if (brick->GetHP() > 0)
			++count;
	}

	if (count > 0)
		return true;
	else
		return false;
}

Direction SGABrickManager::CollisionDir(Circle* circle)
{
	for (SGABrick* brick : bricks)
	{
		Direction result = brick->CollisionDir(circle);
	
		if (result != Direction::END)
			return result;
	}

	return Direction::END;
}
