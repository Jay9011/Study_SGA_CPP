#pragma once

namespace Math
{
	float Distance(D3DXVECTOR2 p1, D3DXVECTOR2 p2);
	
	float DegreeToRadian(float degree);
	float RadianToDegree(float radian);

	int	    Random(const    int& _min, const    int& _max);	// max exclusive : C++은 base 0 이기 때문에 최댓값-1 을 기준으로 한다. (배열이나 for로 쓰일 수 있도록)
	float  Random(const float& _min, const float& _max);	// max inclusive : 실수형은 base 0 과 관련이 없기에 최댓값을 포함한다.
}
