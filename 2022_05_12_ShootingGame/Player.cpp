#include "Framework.h"
#include "Player.h"

Player::Player()
	: maxHp(3)
	, curHp(maxHp)
	, maxScore(999999999)
	, score(0)
	, invincibility(false)
	, bodyFrame({ 2, 0 })
	, velocity(3)
	, curReloadTime(0)
	, maxReloadTime(10)
	, frameTime(0)
	, oldpen(nullptr)
	, oldbrush(nullptr)
	, state(PLAYERSTATE::NONE)
{
	bodyImgRect = new Rect( { WIN_CENTER_X, (double)(WIN_HEIGHT - 50) }
					,		{ 16, 24 });
	bodyImg = TextureManager::Get()->AddTexture("player", L"Textures/PlayerShip.png", 5, 2);

	collider = new Rect(bodyImgRect->Pos(), {15, 15});

	// Debug
	pen = CreatePen(PS_SOLID, 1, COLOR_RED);
	brush = (HBRUSH)GetStockObject(NULL_BRUSH);
	OutputDebugString(L"Player »ý¼º\n");
}

Player::~Player()
{
	delete collider;
	delete bodyImgRect;

	// Debug
	DeleteObject(pen);
	OutputDebugString(L"~Player ¼Ò¸ê\n");
}

void Player::Update()
{
	state = PLAYERSTATE::NONE;
	if (curReloadTime < maxReloadTime)
	{
		++curReloadTime;
	}

	if (GetAsyncKeyState(VK_LEFT))
	{
		bodyImgRect->Pos() += Vector2(-1, 0) * velocity;

		if (bodyImgRect->Left() < 0)
		{
			bodyImgRect->Pos().x = bodyImgRect->Size().x * 0.5;
		}

		state = PLAYERSTATE::MOVE_LEFT;
	}
	else if (GetAsyncKeyState(VK_RIGHT))
	{
		bodyImgRect->Pos() += Vector2(+1, 0) * velocity;

		if (bodyImgRect->Right() > WIN_WIDTH)
		{
			bodyImgRect->Pos().x = WIN_WIDTH - bodyImgRect->Size().x * 0.5;
		}

		state = PLAYERSTATE::MOVE_RIGHT;
	}

	if (GetAsyncKeyState(VK_SPACE))
	{
		if (curReloadTime >= maxReloadTime)
		{
			curReloadTime = 0;
			BulletManager::Get()->PlayerFire({ collider->Pos().x, collider->Top() }, { 0, -1 });
		}
	}

	// collider Update
	collider->Pos() = { bodyImgRect->Pos().x, bodyImgRect->Pos().y - 2 };

	// frame Change
	++frameTime;
	if (frameTime > 10)
	{
		frameTime = 0;
		++bodyFrame.y %= 2;

		switch (state)
		{
		case PLAYERSTATE::MOVE_LEFT:
			if (bodyFrame.x > 0)
			{
				--bodyFrame.x;
			}
			break;
		case PLAYERSTATE::MOVE_RIGHT:
			if (bodyFrame.x < 4)
			{
				++bodyFrame.x;
			}
			break;
		case PLAYERSTATE::NONE:
			bodyFrame.x = 2;
			break;
		}
	}
}

void Player::Render(HDC hdc)
{
	bodyImg->Render(bodyImgRect, bodyFrame);
	
	// Debug
	oldpen   = (HPEN)	SelectObject(hdc, pen);
	oldbrush = (HBRUSH) SelectObject(hdc, brush);
	collider->Render(hdc);
	SelectObject(hdc, oldpen);
	SelectObject(hdc, oldbrush);
}