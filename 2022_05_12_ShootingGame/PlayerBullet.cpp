#include "Framework.h"
#include "PlayerBullet.h"

PlayerBullet::PlayerBullet(Texture* _bulletImg, Texture* _destroyImg)
	: Bullet(_bulletImg, _destroyImg)
{
	velocity = 8;
	bulletFrame.y = 1;
	collider->Radius() = 4;

	// Debug
	OutputDebugString(L"PlayerBullet »ý¼º\n");
}

PlayerBullet::~PlayerBullet()
{
	// Debug
	OutputDebugString(L"~PlayerBullet ¼Ò¸ê\n");
}

void PlayerBullet::Update()
{
	Bullet::Update();

	bulletImgRect->Pos().y += 3;
	if (isUse)
	{
		++frameTime;
		if (frameTime > 3)
		{
			frameTime = 0;
			++bulletFrame.x %= 2;
		}
	}
}

void PlayerBullet::Render(HDC hdc)
{
	if (isUse)
	{
		bulletImg->Render(bulletImgRect, bulletFrame);
	}

	Bullet::Render(hdc);
}

void PlayerBullet::Fire(Vector2 pos, Vector2 dir)
{
	Bullet::Fire(pos, dir);
}