#include "Framework.h"
#include "SGABall.h"

SGABall::SGABall()
	: speed(10)
{
	circle = new Circle({ 0, 0 }, 10);

	dir = { 1 , -1 };
	dir.Normalize();

	whiteBrush = CreateSolidBrush(COLOR_WHITE);
}

SGABall::~SGABall()
{
	delete circle;
	DeleteObject(whiteBrush);
}

void SGABall::Update()
{
}

void SGABall::Render(HDC hdc)
{
	SelectObject(hdc, whiteBrush);
	circle->Render(hdc);
}
