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
		if (ball->Left() < ui->GetStageLeft())
		{
			ball->ChangeDirection(true, false);
		}
		else if (ball->Right() > ui->GetStageRight())
		{
			ball->ChangeDirection(true, false);
		}

		if (ball->Top() < ui->GetStageTop())
		{
			ball->ChangeDirection(false, true);
		}
		else if (ball->Bottom() > ui->GetStageBottom())
		{
			ball->DeleteBall();
		}
	}

	// Player & Ball Collision Check
	for (AKBall* ball : ballManager->Balls())
	{
		if (ball->IsFire())
		{
			Circle circle = Circle(ball->Pos(), ball->Radius());
			Rect rect = Rect(player->GetPos(), player->GetSize());
			Collision(&circle, &rect);

			ball->ChangeDirection(false, true);
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
bool AKCollisionManager::Collision(Rect* rect, Vector2 point)
{
	if (point.x > rect->Left() && point.x < rect->Right() && point.y > rect->Top() && point.y < rect->Bottom())
		return true;

	return false;
}

bool AKCollisionManager::Collision(Rect* r1, Rect* r2)
{
	if(r1->Right() > r2->Left() && r1->Left() < r2->Right() && r1->Bottom() > r2->Top() && r1->Top() < r2->Bottom())
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

bool AKCollisionManager::Collision(Circle* c1, Circle* c2)
{
	if (c1->Radius() + c2->Radius() > Distance(c1->Pos(), c2->Pos()))
		return true;

	return false;
}

bool AKCollisionManager::Collision(Circle* circle, Rect* rect)
{
	Vector2 center = circle->Pos();

	if ((center.x > rect->Left() && center.x < rect->Right()) || (center.y > rect->Top() && center.y < rect->Bottom()))
	{
		Rect cRect(center, { circle->Radius() * 2 , circle->Radius() * 2 });

		return Collision(&cRect, rect);
	}
	else
	{
		Vector2 edges[4];

		edges[0] = { rect->Left(),  rect->Top() };
		edges[1] = { rect->Right(), rect->Top() };
		edges[2] = { rect->Left(),  rect->Bottom() };
		edges[3] = { rect->Right(), rect->Bottom() };

		for (UINT i = 0; i < 4; i++)
		{
			if (Collision(circle, edges[i]))
				return true;
		}
	}

	return false;
}
