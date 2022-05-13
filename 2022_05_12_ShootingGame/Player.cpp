#include "Framework.h"
#include "Player.h"

Player::Player()
	: maxHp(3)
	, curHp(maxHp)
	, maxScore(999999999)
	, score(0)
	, invincibility(false)
	, inviTime(0)
	, bodyFrame({ 2, 0 })
	, bodyHide(false)
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

	graphics = new Gdiplus::Graphics(backDC);

	// Debug
	//pen = CreatePen(PS_SOLID, 1, COLOR_RED);
	//brush = (HBRUSH)GetStockObject(NULL_BRUSH);
}

Player::~Player()
{
	delete graphics;
	delete collider;
	delete bodyImgRect;

	// Debug
	//DeleteObject(pen);
}

void Player::Update()
{
	state = PLAYERSTATE::NONE;
	if (curReloadTime < maxReloadTime)
	{
		++curReloadTime;
	}

	// Key State
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

	if (invincibility)
	{
		++inviTime;
		if (inviTime > 50)
		{
			invincibility = false;
			inviTime = 0;
		}
		else if (inviTime % 10 == 1)
		{
			bodyHide = !bodyHide;
		}
	}
	else
	{
		if (bodyHide)
			bodyHide = false;

		// Collision Check
		for (auto& bullet : BulletManager::Get()->enemyBullet)
		{
			if (!(bullet->IsUse()))
				continue;

			if (Collision::Collision(collider, bullet->GetCollider()))
			{
				bullet->Destroy();
				--curHp;
				invincibility = true;
			}
		}
	}
}

void Player::Render(HDC hdc)
{
	if (bodyHide)
	{
		bodyImg->Render(bodyImgRect, { -1, -1 });
	}
	else
	{
		bodyImg->Render(bodyImgRect, bodyFrame);
	}

	Rect LifeRect = Rect({20.0, WIN_HEIGHT - 20.0}, { 11, 16 });

	for (int i = 0; i < curHp; i++)
	{
		bodyImg->Render(&LifeRect, { 2, 0 });
		LifeRect.Pos().x += LifeRect.Size().x + 3;
	}

	wstring scoreText = to_wstring(score);
	SetTextAlign(hdc, TA_RIGHT);
	TextOut(hdc, WIN_WIDTH - 20, WIN_HEIGHT - 20, scoreText.c_str(), (int)scoreText.length());
	SetTextAlign(hdc, TA_CENTER);

	// Debug
	//oldpen   = (HPEN)	SelectObject(hdc, pen);
	//oldbrush = (HBRUSH) SelectObject(hdc, brush);
	//collider->Render(hdc);
	//SelectObject(hdc, oldpen);
	//SelectObject(hdc, oldbrush);
}