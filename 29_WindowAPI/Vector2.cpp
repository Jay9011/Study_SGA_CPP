#include "Framework.h"
#include "Vector2.h"

Vector2::Vector2()
	: x(0), y(0)
{
}

Vector2::Vector2(double x, double y)
	: x(x), y(y)
{
}

Vector2::~Vector2()
{
}

double Vector2::VectorToAngle()
{
	return atan2(-y, x);
}

Vector2 Vector2::AngleToVector(double angle)
{
	return Vector2(cos(angle), -sin(angle));
}

double Vector2::Length()
{
	return sqrt(pow(x, 2) + pow(y, 2));
}

Vector2& Vector2::Normalize()
{
	if (Length() >= 1)
	{
		(*this) /= Length();
	}
	return *this;
}

double Vector2::Dot(Vector2& other)
{
	return (this->x * other.x) + (this->y * other.y);
}

double Vector2::Cross(Vector2& other)
{
	return (this->x * other.y) - (this->y * other.x);
}

bool Vector2::IsBetween(Vector2& v1, Vector2& v2)
{
	return this->Cross(v1) * this->Cross(v2) < 0;	// - - => +, + + => + (부호가 다르면 => -)
}



/*
*	operator Overloading
*/

Vector2 Vector2::operator+(const Vector2& other) const
{
	return Vector2(this->x + other.x, this->y + other.y);
}

Vector2 Vector2::operator-(const Vector2& other) const
{
	return Vector2(this->x - other.x, this->y - other.y);
}

void Vector2::operator+=(const Vector2& other)
{
	this->x += other.x;
	this->y += other.y;
}

void Vector2::operator-=(const Vector2& other)
{
	this->x -= other.x;
	this->y -= other.y;
}

Vector2 Vector2::operator*(const double& other) const
{
	return Vector2(this->x * other, this->y * other);
}

Vector2 Vector2::operator/(const double& other) const
{
	return Vector2(this->x / other, this->y / other);
}

void Vector2::operator*=(const double& other)
{
	this->x *= other;
	this->y *= other;
}

void Vector2::operator/=(const double& other)
{
	this->x /= other;
	this->y /= other;
}
