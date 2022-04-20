#include "Framework.h"
#include "Line.h"

Line::Line()
	: start(0, 0), end(0, 0)
{
}

Line::Line(Point start, Point end)
	: start(start), end(end)
{
}

Line::~Line()
{
}

void Line::Render(HDC hdc)
{
	MoveToEx(hdc, start.x, start.y, nullptr);
	  LineTo(hdc,   end.x,   end.y);
}

bool Line::IsBetween(Line* other)
{
	Point vec1 = other->start - this->start;
	Point vec2 = other->  end - this->start;
	Point vec3 =  this->  end - this->start;

	return (vec1.Cross(vec3) * vec2.Cross(vec3)) < 0;	// - - => +, + + => + (부호가 다르면 => -)
}
