#include "Framework.h"
#include "Rect.h"

Rect::Rect()
	: pos(0, 0), size(0, 0)
{
}

Rect::Rect(Point pos, Point size)
	: pos(pos), size(size)
{
}

Rect::Rect(double left, double top, double right, double bottom)
{
	pos.x = (right  + left) * 0.5;
	pos.y = (bottom + top ) * 0.5;

	size.x = abs(right  - left);
	size.y = abs(bottom - top );
}

Rect::~Rect()
{
}

void Rect::Render(HDC hdc)
{
	Rectangle(hdc, Left(), Top(), Right(), Bottom());
}
