#pragma once

class Circle
{
public:
	Circle();
	Circle(Point pos, double radius);
	~Circle();

	void Render(HDC hdc);
	
	double Left()   { return this->pos.x - radius; }
	double Right()  { return this->pos.x + radius; }
	double Top()    { return this->pos.y - radius; }
	double Bottom() { return this->pos.y + radius; }

	Point&     Pos() { return pos; }
	double& Radius() { return radius; }
private:
	Point  pos;
	double radius;
};
