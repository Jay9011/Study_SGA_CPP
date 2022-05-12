#include "Framework.h"
#include "AKCollisionManager.h"

AKCollisionManager::AKCollisionManager(AKUI* _ui, AKPlayer* _player, AKBallManager* _ballManager, AKStageManager* _stageManager)
	: ui(_ui)
	, player(_player)
	, ballManager(_ballManager)
	, stageManager(_stageManager)
	, oldBrush(nullptr)
{
	redBrush = CreateSolidBrush(COLOR_RED);
}

AKCollisionManager::~AKCollisionManager()
{
	DeleteObject(redBrush);
}

void AKCollisionManager::Update()
{
	// UI & Ball Collision
	for (AKBall* ball : ballManager->arkanoidBalls)
	{
		Collision(ball, ui);
	}
	
	// Player & Ball Collision
	for (AKBall* ball : ballManager->arkanoidBalls)
	{
		if (ball->IsFire())
		{
			Collision(ball, player);
		}
	}

	// Brick & Ball Collision
	for (AKBall* ball : ballManager->arkanoidBalls)
	{
		if (ball->IsFire())
		{
			for (AKBrick* brick : stageManager->bricks)
			{
				if (brick->isUse && brick->GetHp() > 0)
				{
					Collision(ball, brick);
				}
			}
		}
	}
}

void AKCollisionManager::Render(HDC hdc)
{
}


/// <summary>
/// Collision
/// </summary>
bool AKCollisionManager::Collision(Rect* r1, Rect* r2)
{
	if (r1->Right() > r2->Left() && r1->Left() < r2->Right() && r1->Bottom() > r2->Top() && r1->Top() < r2->Bottom())
		return true;

	return false;
}

bool AKCollisionManager::Collision(Circle* circle, Vector2 point)
{
	double distance = Distance(circle->Pos(), point);

	if (circle->Radius() > distance)
		return true;

	return false;
}

bool AKCollisionManager::Collision(AKBall* _ball, AKUI* _ui)
{
	bool isCollision = false;

	if (_ball->Left() < _ui->GetStageLeft())
	{
		_ball->ChangeDirection(true, false);
		_ball->Pos().x = _ui->GetStageLeft() + _ball->Radius();
		isCollision = true;
	}
	else if (_ball->Right() > _ui->GetStageRight())
	{
		_ball->ChangeDirection(true, false);
		_ball->Pos().x = _ui->GetStageRight() - _ball->Radius();
		isCollision = true;
	}

	if (_ball->Top() < _ui->GetStageTop())
	{
		_ball->ChangeDirection(false, true);
		_ball->Pos().y = _ui->GetStageTop() + _ball->Radius();
		isCollision = true;
	}
	else if (_ball->Bottom() > _ui->GetStageBottom())
	{
		player->AddLife(-1);
		_ball->DeleteBall();
		_ball->Pos().y = _ui->GetStageBottom() - _ball->Radius();
		isCollision = true;
	}

	return isCollision;
}

bool AKCollisionManager::Collision(AKBall* _ball, AKPlayer* _player)
{
	Vector2 bCenter = _ball->Pos();
	Rect* pRect = _player->GetRect();

	if ((bCenter.x > pRect->Left() && bCenter.x < pRect->Right()) || (bCenter.y > pRect->Top() && bCenter.y < pRect->Bottom()))
	{
		Rect bRect(bCenter, { _ball->Radius() * 2, _ball->Radius() * 2 });
		if (Collision(&bRect, pRect))
		{
			Vector2 dir = Vector2(_ball->Pos().x, pRect->Top()) - _player->GetCore();
			dir.Normalize();
			_ball->SetDir(dir);

			return true;
		}
	}
	else
	{
		Vector2 edges[4];

		edges[0] = { pRect->Left(),  pRect->Top() };
		edges[1] = { pRect->Right(), pRect->Top() };
		edges[2] = { pRect->Left(),  pRect->Bottom() };
		edges[3] = { pRect->Right(), pRect->Bottom() };

		for (UINT i = 0; i < 4; i++)
		{
			if (Collision(_ball->GetCircle(), edges[i]))
			{
				Vector2 dir = Vector2(_ball->Pos().x, pRect->Top()) - _player->GetCore();
				dir.Normalize();
				_ball->SetDir(dir);

				return true;
			}
		}
	}

	return false;
}

bool AKCollisionManager::Collision(AKBall* _ball, AKBrick* _brick)
{
	bool isCollision = false;
	Vector2 bCenter = _ball->Pos();
	Rect* brickRect = _brick->GetRect();

	// horizontal Collision
	if (bCenter.x > brickRect->Left() && bCenter.x < brickRect->Right())
	{
		Rect bRect(bCenter, { _ball->Radius() * 2, _ball->Radius() * 2 });
		if (Collision(&bRect, brickRect))
		{
			_ball->ChangeDirection(false, true);
			// top Collision
			if (bCenter.y < brickRect->Pos().y)
			{
				_ball->Pos().y = brickRect->Top() - _ball->Radius();
			}
			// bottom Collision
			else if (bCenter.y > brickRect->Pos().y)
			{
				_ball->Pos().y = brickRect->Bottom() + _ball->Radius();
			}
			isCollision = true;
		}
	}
	// vertical Collision
	if (bCenter.y > brickRect->Top() && bCenter.y < brickRect->Bottom())
	{
		Rect bRect(bCenter, { _ball->Radius() * 2, _ball->Radius() * 2 });
		if (Collision(&bRect, brickRect))
		{
			_ball->ChangeDirection(true, false);
			// left Collision
			if (bCenter.x < brickRect->Pos().x)
			{
				_ball->Pos().x = brickRect->Left() - _ball->Radius();
			}
			// right Collision
			else if (bCenter.x > brickRect->Pos().x)
			{
				_ball->Pos().x = brickRect->Right() + _ball->Radius();
			}
			isCollision = true;
		}
	}
	else
	{
		Vector2 edges[4];

		edges[0] = { brickRect->Left(),  brickRect->Top() };
		edges[1] = { brickRect->Right(), brickRect->Top() };
		edges[2] = { brickRect->Left(),  brickRect->Bottom() };
		edges[3] = { brickRect->Right(), brickRect->Bottom() };

		for (UINT i = 0; i < 4; i++)
		{
			if (Collision(_ball->GetCircle(), edges[i]))
			{
				Vector2 brickVec = bCenter - brickRect->Pos();
				brickVec.Normalize();
				Vector2 dir = brickVec - _ball->Dir();
				dir.Normalize();
				_ball->SetDir(dir);

				isCollision = true;
			}
		}
	}

	if (isCollision)
	{
		_brick->MinusHp(1);
		ui->SetScore(20);
	}

	return isCollision;
}
