#include "Framework.h"
#include "Math.h"

double Math::Distance(Point p1, Point p2)
{
	double distance;

	double x = p1.x - p2.x;
	double y = p1.y - p2.y;

	distance = sqrt(x * x + y * y);

	return distance;
}
