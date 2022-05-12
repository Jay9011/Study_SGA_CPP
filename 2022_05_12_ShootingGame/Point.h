#pragma once

class Point
{
public:
	Point()
		:x(0), y(0)
	{
	}

	Point(double x, double y)
		:x(x), y(y)
	{
	}

	Point operator - (const Point& point)
	{
		return Point(this->x - point.x, this->y - point.y);
	}

	double Cross(const Point& other)
	{
		return (this->x * other.y) - (this->y * other.x);
	}

	~Point()
	{
	}

	double x;
	double y;
};

