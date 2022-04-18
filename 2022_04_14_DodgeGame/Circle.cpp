#include "Framework.h"
#include "Circle.h"

Circle::Circle()
	: pos(0, 0), radius(0)
{
}

Circle::Circle(Point pos, double radius)
	: pos(pos), radius(radius)
{
}

Circle::~Circle()
{
}

void Circle::Render(HDC hdc)
{
	Ellipse(hdc, (int)Left(), (int)Top(), (int)Right(), (int)Bottom());
}
