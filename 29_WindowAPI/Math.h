#pragma once

namespace Math
{
	double Distance(Vector2 p1, Vector2 p2);
	
	double DegreeToRadian(double degree);
	double RadianToDegree(double radian);

	int	    Random(const    int& _min, const    int& _max);	// max exclusive : C++�� base 0 �̱� ������ �ִ�-1 �� �������� �Ѵ�. (�迭�̳� for�� ���� �� �ֵ���)
	double  Random(const double& _min, const double& _max);	// max inclusive : �Ǽ����� base 0 �� ������ ���⿡ �ִ��� �����Ѵ�.
}
