#include "Framework.h"
#include "EnemyBullet.h"

EnemyBullet::EnemyBullet(Texture* _bulletImg, Texture* _destroyImg)
	: Bullet(_bulletImg, _destroyImg)
{
	velocity = 300;
	bulletFrame.y = 0;
	collider->Radius() = 3;
}

EnemyBullet::~EnemyBullet()
{
}

void EnemyBullet::Update()
{
	Bullet::Update();

	bulletImgRect->Pos() = collider->Pos();
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

void EnemyBullet::Render(HDC hdc)
{
	if (isUse)
	{
		bulletImg->Render(bulletImgRect, bulletFrame);
	}

	Bullet::Render(hdc);
}

void EnemyBullet::Fire(Vector2 pos, Vector2 dir)
{
	Bullet::Fire(pos, dir);
}
