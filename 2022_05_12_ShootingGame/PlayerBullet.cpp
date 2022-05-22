#include "Framework.h"
#include "PlayerBullet.h"

PlayerBullet::PlayerBullet(Texture* _bulletImg, Texture* _destroyImg)
	: Bullet(_bulletImg, _destroyImg)
{
	velocity = 480;
	bulletFrame.y = 1;
	collider->Radius() = 4;
}

PlayerBullet::~PlayerBullet()
{
}

void PlayerBullet::Update()
{
	Bullet::Update();

	bulletImgRect->Pos().y += 3;
	if (isUse)
	{
		frameTime += Time::Delta();
		if (frameTime > .05)
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