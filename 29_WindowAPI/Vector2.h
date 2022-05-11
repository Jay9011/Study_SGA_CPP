#pragma once

#define V_LEFT	Vector2(-1,  0)
#define V_RIGHT	Vector2(+1,  0)
#define V_UP  	Vector2( 0, -1)
#define V_DOWN	Vector2( 0, +1)

class Vector2
{
public:
	double x;
	double y;

	Vector2();
	Vector2(double x, double y);
	~Vector2();

	double  VectorToAngle();
	Vector2 AngleToVector(double angle);

	double	   Length();
	void	Normalize();

	double	  Dot(Vector2& other);
	double	Cross(Vector2& other);

	bool	IsBetween(Vector2& v1, Vector2& v2);

	Vector2 operator + (const Vector2& other) const;
	Vector2 operator - (const Vector2& other) const;

	void operator += (const Vector2& other);
	void operator -= (const Vector2& other);

	Vector2 operator * (const double& other) const;
	Vector2 operator / (const double& other) const;

	void operator *= (const double& other);
	void operator /= (const double& other);
};
