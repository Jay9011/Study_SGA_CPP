#pragma once
class Rect : public Object
{
public:
	Rect();
	Rect(Point pos, Point size);
	Rect(double left, double top, double right, double bottom);
	~Rect();

	void Render(HDC hdc);

	double Left()	{ return pos.x - (size.x * 0.5); }
	double Right()	{ return pos.x + (size.x * 0.5); }
	double Top()	{ return pos.y - (size.y * 0.5); }
	double Bottom() { return pos.y + (size.y * 0.5); }

	Point& Pos()	{ return pos; }
	Point& Size()	{ return size; }

private:
	Point pos;
	Point size;
};

