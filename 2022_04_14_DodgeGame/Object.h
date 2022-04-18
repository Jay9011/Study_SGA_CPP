#pragma once
class Object
{
public:
	Object();
	virtual ~Object();

	virtual void Render(HDC hdc) = 0;

	virtual Point& Pos() = 0;
};