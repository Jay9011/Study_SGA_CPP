#pragma once

namespace Math
{
	double Distance(Vector2 p1, Vector2 p2);
	
	double DegreeToRadian(double degree);
	double RadianToDegree(double radian);

	int	    Random(const    int& _min, const    int& _max);	// max exclusive : C++은 base 0 이기 때문에 최댓값-1 을 기준으로 한다. (배열이나 for로 쓰일 수 있도록)
	double  Random(const double& _min, const double& _max);	// max inclusive : 실수형은 base 0 과 관련이 없기에 최댓값을 포함한다.
}
