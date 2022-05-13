#include "Framework.h"
#include "Bullet.h"

Bullet::Bullet()
	: isUse(false)
	, bulletFrame({ 0, 0 })
	, velocity(5)
	, frameTime(0)
	, oldpen(nullptr)
	, oldbrush(nullptr)
{
	bulletImgRect = new Rect({ 0, 0 }, { 16, 16 });
	bulletImg = TextureManager::Get()->AddTexture("Bullet", L"Textures/Bullet.png", 2, 2);

	collider = new Circle({ 0, 0 }, 8);

	// Debug
	pen = CreatePen(PS_SOLID, 1, COLOR_RED);
	brush = (HBRUSH)GetStockObject(NULL_BRUSH);
	OutputDebugString(L"Bullet »ý¼º\n");
}

Bullet::~Bullet()
{
	delete collider;
	delete bulletImgRect;
	
	// Debug
	DeleteObject(pen);
	
	OutputDebugString(L"~Bullet ¼Ò¸ê\n");
}

void Bullet::Update()
{
	if (isUse)
	{
		collider->Pos() += direction * velocity;
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
	if (isUse)
	{

		// Debug
		oldpen = (HPEN)SelectObject(hdc, pen);
		oldbrush = (HBRUSH)SelectObject(hdc, brush);
		collider->Render(hdc);
		SelectObject(hdc, oldpen);
		SelectObject(hdc, oldbrush);
	}
}

void Bullet::Fire(Vector2 pos, Vector2 dir)
{
	isUse = true;
	collider->Pos() = pos;
	direction = dir;
}

void Bullet::ResetBullet()
{
	isUse = false;
	collider->Pos() = Vector2(0, 0);
	frameTime = 0;
}
