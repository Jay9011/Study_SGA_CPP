#include "Framework.h"
#include "SGABall.h"

SGABall::SGABall()
	: speed(10)
	, isPlay(false)
	, barRect(nullptr)
{
	circle = new Circle({ 0, 0 }, 10);

	initDir = { 1, -1 };
	initDir.Normalize();
	dir = initDir;

	whiteBrush = CreateSolidBrush(COLOR_WHITE);
}

SGABall::~SGABall()
{
	delete circle;
	DeleteObject(whiteBrush);
}

void SGABall::Update()
{
	if (GetAsyncKeyState(VK_SPACE))
		isPlay = true;

	if (isPlay)
	{
		circle->Pos() += dir * speed;

		CollisionBar();
		CollisionWall();
		CollisionBrick();
	}
	else
	{
		circle->Pos() = Vector2(barRect->Pos().x, barRect->Top() - circle->Radius());
	}

}

void SGABall::Render(HDC hdc)
{
	SelectObject(hdc, whiteBrush);
	circle->Render(hdc);
}

void SGABall::CollisionBar()
{
	if (Collision::Collision(barRect, circle))
	{
		dir = (circle->Pos() - Vector2(barRect->Pos().x, barRect->Bottom() + circle->Radius()));
		dir.Normalize();
	}
}

void SGABall::CollisionWall()
{
	if (circle->Left() < 0)
	{
		dir.x *= -1;
		circle->Pos().x = circle->Radius();
	}
	else if (circle->Right() > WIN_WIDTH)
	{
		dir.x *= -1;
		circle->Pos().x = WIN_WIDTH - circle->Radius();
	}

	if (circle->Top() < 0)
	{
		dir.y *= -1;
		circle->Pos().y = circle->Radius();
	}
	else if (circle->Bottom() > WIN_HEIGHT)
	{
		isPlay = false;
		dir = initDir;
		barRect->Pos().x = WIN_WIDTH * 0.5;
	}
}

void SGABall::CollisionBrick()
{
	Direction result = bm->CollisionDir(circle);

	switch (result)
	{
	case Direction::LEFT:
	case Direction::RIGHT:
		dir.x *= -1;
		break;
	case Direction::UP:
	case Direction::DOWN:
		dir.y *= -1;
		break;
	case Direction::END:
		break;
	default:
		break;
	}

	if (!bm->GetRemainBricks())
	{
		isPlay = false;
		dir = initDir;
		bm->ClearStage();
		bm->CreateStage2();
	}
}
