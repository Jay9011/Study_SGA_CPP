#include "Framework.h"
#include "Math.h"

float Math::Distance(Vector2 p1, Vector2 p2)
{
	float distance;

	float x = p1.x - p2.x;
	float y = p1.y - p2.y;

	distance = sqrt(pow(x, 2) + pow(y, 2));

	return distance;
}

float Math::DegreeToRadian(float degree)
{
	return degree * PI / 180.0f;
}

float Math::RadianToDegree(float radian)
{
	return radian * 180.0f / PI;
}

int Math::Random(const int& min, const int& max)
{
	return rand() % (max - min) + min;
}

float Math::Random(const float& min, const float& max)
{
	float val = (float)rand() / RAND_MAX;

	return min + (max - min) * val;
	//min ~ max
	//min = min + (max - min) * 0;
	//max = min + (max - min) * 1;
}
