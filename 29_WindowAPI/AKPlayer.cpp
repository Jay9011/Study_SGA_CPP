#include "Framework.h"
#include "AKPlayer.h"

AKPlayer::AKPlayer(AKUI* _akui, AKBallManager* _akbm)
	: speed(10)
	, life(2)
	, arkanoidUI(_akui)
	, arkanoidBallManager(_akbm)
	, readyBall(nullptr)
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

		if (body->Left() < arkanoidUI->GetStageLeft())
		{
			body->Pos().x = arkanoidUI->GetStageLeft() + (body->Size().x / 2);
		}
		else
		{
			if (readyBall)
			{
				readyBall->SetPos(readyBall->Pos() + (Vector2(-1, 0) * speed));
			}
		}

	}
	else if (GetAsyncKeyState(VK_RIGHT))
	{
		body->Pos() += Vector2(1, 0) * speed;

		if (body->Right() > arkanoidUI->GetStageRight())
		{
			body->Pos().x = arkanoidUI->GetStageRight() - (body->Size().x / 2);
		}
		else 
		{
			if (readyBall)
			{
				readyBall->SetPos(readyBall->Pos() + (Vector2(1, 0) * speed));
			}
		}

	}

	if (GetAsyncKeyState(VK_SPACE))
	{
		arkanoidBallManager->Fire(Vector2(0, -1));
		readyBall = nullptr;
	}

	if (!arkanoidBallManager->GetReady())
	{
		readyBall = arkanoidBallManager->SetReady(GetTopCenter());
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
