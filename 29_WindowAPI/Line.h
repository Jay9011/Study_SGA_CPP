#pragma once
class Line
{
public:
	Line();
	Line(Point start, Point end);
	~Line();

	void Render(HDC hdc);
	bool IsBetween(Line* other);

	Point& Start() { return start; }
	Point&   End() { return   end; }

private:
	Point start;
	Point	end;
};
