#include "Framework.h"
#include "Math.h"

double Math::Distance(Vector2 p1, Vector2 p2)
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

int Math::Random(const int& _min, const int& _max)
{
	return rand() % (_max - _min) + _min;
}

double Math::Random(const double& _min, const double& _max)
{
	// min ~ max
	// min = min + (max - min) * 0;
	// max = min + (max - min) * 1;

	double val = (double)rand() / RAND_MAX;

	return _min + (_max - _min) * val;
}
