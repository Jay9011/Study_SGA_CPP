#include "Framework.h"
#include "Math.h"

double Math::Distance(Point p1, Point p2)
{
	double distance;

	double x = p1.x - p2.x;
	double y = p1.y - p2.y;

	distance = sqrt(x * x + y * y);
			// sqrt(pow(x, 2) + pow(y, 2));

	return distance;
}

double Math::DegreeToRadian(double degree)
{
	return degree / 180 * PI;
}

double Math::RadianToDegree(double radian)
{
	return radian / PI * 180;
}
