#include "Framework.h"
#include "AKCollisionManager.h"

AKCollisionManager::AKCollisionManager(AKUI* _ui, AKPlayer* _player, AKBallManager* _ballManager)
	: ui(_ui)
	, player(_player)
	, ballManager(_ballManager)
{
	redBrush = CreateSolidBrush(COLOR_RED);
}

AKCollisionManager::~AKCollisionManager()
{
	DeleteObject(redBrush);
}

void AKCollisionManager::Update()
{
	// UI & Ball Collision Check
	for (AKBall* ball : ballManager->Balls())
	{
		Collision(ball, ui);
	}

	// Player & Ball Collision Check
	for (AKBall* ball : ballManager->Balls())
	{
		if (ball->IsFire())
		{
			Collision(ball, player);
		}
	}
}

void AKCollisionManager::Render(HDC hdc)
{
	oldBrush = (HBRUSH)SelectObject(hdc, redBrush);
	for (auto& ball : ballManager->Balls())
	{
		Rectangle(hdc
			, ball->Pos().x - 4
			, ball->Bottom() - 4
			, ball->Pos().x + 4
			, ball->Bottom() + 4
			);
	}
	SelectObject(hdc, oldBrush);
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
		isCollision = true;
	}
	else if (_ball->Right() > _ui->GetStageRight())
	{
		_ball->ChangeDirection(true, false);
		isCollision = true;
	}

	if (_ball->Top() < _ui->GetStageTop())
	{
		_ball->ChangeDirection(false, true);
		isCollision = true;
	}
	else if (_ball->Bottom() > _ui->GetStageBottom())
	{
		_ball->DeleteBall();
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
