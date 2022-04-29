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

void Vector2::Normalize()
{
	if (Length() >= 1)
	{
		(*this) /= Length();
	}
}

double Vector2::Dot(Vector2& other)
{
	return (this->x * other.x) + (this->y * other.y);
}

double Vector2::Cross(Vector2& other)
{
	return (this->x * other.y) - (this->y * other.x);
}
