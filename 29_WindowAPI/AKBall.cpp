#include "Framework.h"
#include "AKBall.h"

AKBall::AKBall()
	: speed(10)
	, isReady(false)
	, isFire(false)
	, oldPen(nullptr)
	, oldBrush(nullptr)
{
	ball = new Circle({ 0, 0 }, 10);

	blackPen = CreatePen(PS_SOLID, 2, COLOR_BLACK);
	cyanPen  = CreatePen(PS_SOLID, 2, COLOR_CYAN);
	bluePen  = CreatePen(PS_SOLID, 2, COLOR_BLUE);
	blackBrush = CreateSolidBrush(COLOR_BLACK);
	cyanBrush  = CreateSolidBrush(COLOR_CYAN);
	blueBrush  = CreateSolidBrush(COLOR_BLUE);
}

AKBall::~AKBall()
{
	DeleteObject(blackPen);
	DeleteObject(cyanPen);
	DeleteObject(bluePen);
	DeleteObject(blackBrush);
	DeleteObject(cyanBrush);
	DeleteObject(blueBrush);

	delete ball;
}

void AKBall::Update()
{
	if (isReady && isFire)
	{
		ball->Pos() += direction * speed;
	}
}

void AKBall::Render(HDC hdc)
{
	if (isReady)
	{
		oldPen = (HPEN)SelectObject(hdc, bluePen);
		oldBrush = (HBRUSH)SelectObject(hdc, cyanBrush);
		ball->Render(hdc);
		SelectObject(hdc, oldPen);
		SelectObject(hdc, oldBrush);
	}
}

void AKBall::SetReady(Vector2 _pos)
{
	Vector2 position = Vector2(_pos.x, _pos.y - ball->Radius());
	ball->Pos() = position;
	isReady = true;
}

void AKBall::Fire(Vector2 dir)
{
	isFire = true;
	if (!isReady)
		isReady = true;

	direction = dir;
}

void AKBall::Fire(Vector2 pos, Vector2 dir)
{
	ball->Pos() = pos;
	Fire(dir);
}

void AKBall::ChangeDirection(bool _cXPos, bool _cYPos)
{
	if (_cXPos)
		direction.x *= -1;

	if (_cYPos)
		direction.y *= -1;
}