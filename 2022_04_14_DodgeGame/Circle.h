#pragma once
class Circle : public Object
{
public:
	Circle();
	Circle(Point pos, double radius);
	~Circle();

	void Render(HDC hdc);

	double Left()	{ return pos.x - radius; }
	double Right()	{ return pos.x + radius; }
	double Top()	{ return pos.y - radius; }
	double Bottom() { return pos.y + radius; }

	Point&	Pos()	{ return pos; }
	double	Radius(){ return radius; }

private:
	Point pos;
	double radius;
};

