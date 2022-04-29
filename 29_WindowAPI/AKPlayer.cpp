#include "Framework.h"
#include "AKPlayer.h"

AKPlayer::AKPlayer(AKUI& _akui)
	: speed(10)
	, arkanoidUI(&_akui)
	, oldBrush(nullptr)
	, oldPen(nullptr)
{
	Vector2 pos = Vector2((arkanoidUI->GetStageLeft() + arkanoidUI->GetStageRight()) / 2
						 , arkanoidUI->GetStageBottom() - 20
						 );
	body = new Rect(pos, { 150, 25 });

	// Pen & Brush
	bodyColor = CreateSolidBrush(COLOR_GRAY);
	borderColor = CreatePen(PS_SOLID, 2, COLOR_BLACK);
}

AKPlayer::~AKPlayer()
{
	delete body;

	// Pen & Brush
	DeleteObject(bodyColor);
	DeleteObject(borderColor);
}

void AKPlayer::Update()
{
	if (GetAsyncKeyState(VK_LEFT))
	{
		body->Pos() += Vector2(-1, 0) * speed;

		if (body->Pos().x > arkanoidUI->GetStageLeft())
		{
			body->Pos().x = arkanoidUI->GetStageLeft();
		}
	}
	else if (GetAsyncKeyState(VK_RIGHT))
	{
		body->Pos() -= Vector2(1, 0) * speed;
	}
}

void AKPlayer::Render(HDC hdc)
{
	oldPen = (HPEN)SelectObject(hdc, borderColor);
	oldBrush = (HBRUSH)SelectObject(hdc, bodyColor);
	body->Render(hdc);
	SelectObject(hdc, oldPen);
	SelectObject(hdc, oldBrush);
}
