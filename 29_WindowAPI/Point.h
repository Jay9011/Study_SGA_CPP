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

	~Point()
	{
	}

	double x;
	double y;
};

