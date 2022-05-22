#include "Framework.h"
#include "Bullet.h"

Bullet::Bullet(Texture* _bulletImg, Texture* _destroyImg)
	: isUse(false)
	, isDestroying(false)
	, damage(1)
	, velocity(300)
	, bulletImgRectSize({ 16, 16 })
	, bulletFrame({ 0, 0 })
	, destroyImgRectSize({ 16, 16 })
	, destroyFrame({ 0, 0 })
	, frameTime(0)
	, destroyTime(0)
	, oldpen(nullptr)
	, oldbrush(nullptr)
{
	bulletImgRect  = new Rect({ 0, 0 }, bulletImgRectSize);
	destroyImgRect = new Rect({ 0, 0 }, destroyImgRectSize);

	bulletImg  = _bulletImg;
	destroyImg = _destroyImg;

	collider = new Circle({ 0, 0 }, 8);

	// Debug
	//pen = CreatePen(PS_SOLID, 1, COLOR_RED);
	//brush = (HBRUSH)GetStockObject(NULL_BRUSH);
}

Bullet::~Bullet()
{
	delete collider;
	delete destroyImgRect;
	delete bulletImgRect;
	
	// Debug
	DeleteObject(pen);
}

void Bullet::Update()
{
	if (isDestroying)
	{
		Destroy();
		return;
	}

	if (isUse)
	{
		collider->Pos() += direction * velocity * Time::Delta();
		bulletImgRect->Pos() = collider->Pos();

		if (	bulletImgRect->Bottom() < 0
			||	bulletImgRect->Right()	< 0
			||	bulletImgRect->Top()	> WIN_HEIGHT
			||	bulletImgRect->Left()	> WIN_WIDTH
			)
		{
			ResetBullet();
		}
	}
}

void Bullet::Render(HDC hdc)
{
	if (isDestroying)
	{
		destroyImg->Render(destroyImgRect, destroyFrame);
	}

	if (isUse)
	{
		// Debug
		//oldpen = (HPEN)SelectObject(hdc, pen);
		//oldbrush = (HBRUSH)SelectObject(hdc, brush);
		//collider->Render(hdc);
		//SelectObject(hdc, oldpen);
		//SelectObject(hdc, oldbrush);
	}
}

void Bullet::Fire(Vector2 pos, Vector2 dir)
{
	isUse = true;
	collider->Pos() = pos;
	direction = dir;
}

void Bullet::Destroy()
{
	destroyTime += Time::Delta();

	if (!isDestroying)
	{
		isDestroying = true;
		direction = Vector2(0, 0);
		destroyImgRect->Pos() = collider->Pos();
		bulletImgRect->Size() = { 0, 0 };
		collider->Pos() = { -100, -100 };
	}

	if (destroyTime > .05)
	{
		destroyTime = 0;
		++destroyFrame.x;

		if (destroyFrame.x < 5)
			return;

		ResetBullet();
	}
}

void Bullet::ResetBullet()
{
	isUse = false;
	isDestroying = false;
	bulletImgRect->Pos() = { 0, 0 };
	bulletImgRect->Size() = bulletImgRectSize;
	destroyImgRect->Pos() = { 0, 0 };
	destroyImgRect->Size() = destroyImgRectSize;
	destroyFrame = { 0, 0 };
	collider->Pos() = { 0, 0 };
	frameTime = 0;
	destroyTime = 0;
}
