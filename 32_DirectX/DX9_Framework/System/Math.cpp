#include "Framework.h"
#include "Math.h"

float Math::Distance(D3DXVECTOR2 p1, D3DXVECTOR2 p2)
{
	float x = p1.x - p2.x;
	float y = p1.y - p2.y;
	return sqrt(pow(x, 2) + pow(y, 2));
}

float Math::DegreeToRadian(float degree)
{
	return degree / 180.f * PI;
}

float Math::RadianToDegree(float radian)
{
	return radian / PI * 180.f;
}

int Math::Random(const int& _min, const int& _max)
{
	return rand() % (_max - _min) + _min;
}

float Math::Random(const float& _min, const float& _max)
{
	// min ~ max
	// min = min + (max - min) * 0;
	// max = min + (max - min) * 1;

	float val = (float)rand() / RAND_MAX;

	return _min + (_max - _min) * val;
}
