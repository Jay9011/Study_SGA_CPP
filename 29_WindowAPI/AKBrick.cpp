#include "Framework.h"
#include "AKBrick.h"

AKBrick::AKBrick()
	: hp(0)
	, isUse(false)
	, oldPen(nullptr)
	, oldBrush(nullptr)
{
	body = new Rect({ 0, 0 }, { BRICK_WIDTH, BRICK_HEIGHT });

	grayPen		= CreatePen(PS_SOLID, 2, COLOR_GRAY);
	
	redBrush	= CreateSolidBrush(COLOR_RED);
	orangeBrush	= CreateSolidBrush(COLOR_ORANGE);
	yellowBrush	= CreateSolidBrush(COLOR_YELLOW);
	greenBrush	= CreateSolidBrush(COLOR_GREEN);
}

AKBrick::~AKBrick()
{
	delete body;

	DeleteObject(grayPen);
	DeleteObject(redBrush);
	DeleteObject(orangeBrush);
	DeleteObject(yellowBrush);
	DeleteObject(greenBrush);
}

void AKBrick::Update()
{
	if (hp <= 0)
	{
		ResetBrick();
	}
}

void AKBrick::Render(HDC hdc)
{
	if (isUse && GetHp() > 0)
	{
		oldPen = (HPEN)SelectObject(hdc, grayPen);
		switch (hp)
		{
		case 4:
			oldBrush = (HBRUSH)SelectObject(hdc, greenBrush);
			break;
		case 3:
			oldBrush = (HBRUSH)SelectObject(hdc, yellowBrush);
			break;
		case 2:
			oldBrush = (HBRUSH)SelectObject(hdc, orangeBrush);
			break;
		case 1:
			oldBrush = (HBRUSH)SelectObject(hdc, redBrush);
			break;
		}
		body->Render(hdc);
		SelectObject(hdc, oldPen);
		SelectObject(hdc, oldBrush);
	}
}

void AKBrick::ResetBrick()
{
	isUse = false;
	body->Pos() = { 0, 0 };
	body->Size() = { 0, 0 };
}
