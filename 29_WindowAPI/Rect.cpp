#include "Framework.h"
#include "Rect.h"

Rect::Rect()
	:pos(0, 0), size(0, 0)
{
}

Rect::Rect(Point pos, Point size)
	: pos(pos), size(size)
{
}

Rect::Rect(double left, double top, double right, double bottom)
{
	pos.x = (left + right) * 0.5;
	pos.y = (top + bottom) * 0.5;

	size.x = abs(right - left);
	size.y = abs(bottom - top);
}

Rect::~Rect()
{
}

void Rect::Render(HDC hdc)
{
	Rectangle(hdc, (int)Left(), (int)Top(), (int)Right(), (int)Bottom());
}

void Rect::SetRect(double left, double top, double right, double bottom)
{
	pos.x = (left + right) * 0.5;
	pos.y = (top + bottom) * 0.5;

	size.x = abs(right - left);
	size.y = abs(bottom - top);
}
