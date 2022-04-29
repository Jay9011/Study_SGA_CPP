#pragma once

class Circle
{
public:
	Circle();
	Circle(Vector2 pos, double radius);
	~Circle();

	void Render(HDC hdc);
	
	double Left()   { return this->pos.x - radius; }
	double Right()  { return this->pos.x + radius; }
	double Top()    { return this->pos.y - radius; }
	double Bottom() { return this->pos.y + radius; }

	Vector2&     Pos() { return pos; }
	double& Radius() { return radius; }
private:
	Vector2  pos;
	double radius;
};
