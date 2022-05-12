#include "Framework.h"
#include "SGABar.h"

SGABar::SGABar()
	: speed(10)
{
	rect = new Rect({ WIN_WIDTH * 0.5, WIN_HEIGHT * 0.9 }, { 100, 30 });
	
	grayBrush = CreateSolidBrush(COLOR_GRAY);
}

SGABar::~SGABar()
{
	delete rect;
	DeleteObject(grayBrush);
}

void SGABar::Update()
{
	Move();
}

void SGABar::Render(HDC hdc)
{
	SelectObject(hdc, grayBrush);
	rect->Render(hdc);
}

void SGABar::Move()
{
	if (GetAsyncKeyState(VK_LEFT))
	{
		rect->Pos() += Vector2(-1, 0) * speed;
		
		if (rect->Left() < 0)
		{
			rect->Pos().x = rect->Size().x * 0.5;
		}
	}
	else if (GetAsyncKeyState(VK_RIGHT))
	{
		rect->Pos() += Vector2(+1, 0) * speed;

		if (rect->Right() > WIN_WIDTH)
		{
			rect->Pos().x = WIN_WIDTH - rect->Size().x * 0.5;
		}
	}
}
