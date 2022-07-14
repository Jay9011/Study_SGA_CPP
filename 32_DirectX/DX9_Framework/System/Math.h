#pragma once

namespace Math
{
	float Distance(Vector2 p1, Vector2 p2);

	float DegreeToRadian(float degree);
	float RadianToDegree(float radian);

	int	  Random(const   int& min, const   int& max); //max exclusive 최댓값 미포함
	float Random(const float& min, const float& max); //max inclusive 최댓값 포함

}
