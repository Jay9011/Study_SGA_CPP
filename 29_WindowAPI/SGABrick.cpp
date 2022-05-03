#include "Framework.h"
#include "SGABrick.h"

SGABrick::SGABrick()
	: curHP(1)
{
	rect = new Rect(Vector2(WIN_CENTER_X, 100), Vector2(300, 100));

	brushes[0] = CreateSolidBrush(COLOR_YELLOW);
	brushes[1] = CreateSolidBrush(COLOR_ORANGE);
	brushes[2] = CreateSolidBrush(COLOR_PINK);
	brushes[3] = CreateSolidBrush(COLOR_MAGENTA);
	brushes[4] = CreateSolidBrush(COLOR_RED);
}

SGABrick::~SGABrick()
{
	delete rect;

	for (UINT i = 0; i < MAX_HP; i++)
	{
		DeleteObject(brushes[i]);
	}
}

void SGABrick::Render(HDC hdc)
{
	if (curHP <= 0)
		return;
	
	SelectObject(hdc, brushes[curHP - 1]);
	rect->Render(hdc);

}

Direction SGABrick::Collision(Circle* circle)
{
	Vector2 dir = circle->Pos() - rect->Pos();

	Vector2 leftUp	  = Vector2(rect->Size().x * (-0.5), rect->Size().y * (-0.5));
	Vector2 leftDown  = Vector2(rect->Size().x * (-0.5), rect->Size().y * (+0.5));
	Vector2 rightUp   = Vector2(rect->Size().x * (+0.5), rect->Size().y * (-0.5));
	Vector2 rightDown = Vector2(rect->Size().x * (+0.5), rect->Size().y * (+0.5));

	if (Collision::Collision(circle, rect))
	{
		if (dir.IsBetween(leftDown, leftUp))
			return Direction::LEFT;
		else if (dir.IsBetween(leftUp, rightUp))
			return Direction::UP;
		else if (dir.IsBetween(rightUp, rightDown))
			return Direction::RIGHT;
		else if (dir.IsBetween(rightUp, leftDown))
			return Direction::DOWN;
		else
			return Direction::END;
	}

	return Direction::END;
}
