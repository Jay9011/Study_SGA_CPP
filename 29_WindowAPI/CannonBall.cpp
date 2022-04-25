#include "Framework.h"
#include "CannonBall.h"

CannonBall::CannonBall()
	: angle(0), speed(30), isFire(false), gravity(0)
{
	ball = new Circle({ 0, 0 }, 10);
}

CannonBall::~CannonBall()
{
	delete ball;
}

void CannonBall::Update()
{
	if (!isFire)
		return;

	ball->Pos().x += cos(angle) * speed;
	ball->Pos().y -= sin(angle) * speed;

	gravity += 0.98;
	ball->Pos().y += gravity;
}

void CannonBall::Render(HDC hdc)
{
	if (!isFire)
		return;

	ball->Render(hdc);
}

void CannonBall::Fire(Point pos, double angle, double power)
{
	isFire = true;
	ball->Pos() = pos;
	this->angle = angle;

	gravity = 0;

	speed = power * 0.1;
}
