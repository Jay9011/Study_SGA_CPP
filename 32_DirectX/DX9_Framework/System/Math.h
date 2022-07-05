#pragma once

namespace Math
{
	float Distance(D3DXVECTOR2 p1, D3DXVECTOR2 p2);
	
	float DegreeToRadian(float degree);
	float RadianToDegree(float radian);

	int	    Random(const    int& _min, const    int& _max);	// max exclusive : C++�� base 0 �̱� ������ �ִ�-1 �� �������� �Ѵ�. (�迭�̳� for�� ���� �� �ֵ���)
	float  Random(const float& _min, const float& _max);	// max inclusive : �Ǽ����� base 0 �� ������ ���⿡ �ִ��� �����Ѵ�.
}
