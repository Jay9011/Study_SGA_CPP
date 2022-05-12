#pragma once

class Rect
{
public:
	Rect();
	Rect(Vector2 pos, Vector2 size);
	Rect(double left, double top, double right, double bottom);

	~Rect();

	void Render(HDC hdc);

	void SetRect(double left, double top, double right, double bottom);

	double Left()   { return this->pos.x - size.x * 0.5; }
	double Right()  { return this->pos.x + size.x * 0.5; }
	double Top()    { return this->pos.y - size.y * 0.5; }
	double Bottom() { return this->pos.y + size.y * 0.5; }

	Vector2&  Pos() { return pos; }
	Vector2& Size() { return size; }

private:
	Vector2 pos;
	Vector2 size;
};
