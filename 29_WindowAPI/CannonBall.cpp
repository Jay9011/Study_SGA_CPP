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

	/*gravity += 0.98;
	ball->Pos().y += gravity;*/

	/*
	*	���� ȭ�鿡 ƨ��� ����
	*/
	// ���� �� �ݻ�
	if (ball->Left() < 0)
	{
		angle = PI - angle;
		ball->Pos().x = ball->Radius();
	}
	// ������ �� �ݻ�
	if (ball->Right() > WIN_WIDTH)
	{
		angle = PI - angle;
		ball->Pos().x = WIN_WIDTH - ball->Radius();
	}
	// ���� �� �ݻ�
	if (ball->Top() < 0)
	{
		angle = -angle;
		ball->Pos().y = ball->Radius();
	}
	// �Ʒ��� �� �ݻ�
	if (ball->Bottom() > WIN_HEIGHT)
	{
		angle *= -1;
		ball->Pos().y = WIN_HEIGHT - ball->Radius();
	}
}

void CannonBall::Render(HDC hdc)
{
	if (!isFire)
		return;

	ball->Render(hdc);
}

void CannonBall::Fire(Vector2 pos, double angle, double power)
{
	isFire = true;
	ball->Pos() = pos;
	this->angle = angle;

	/*gravity = 0;*/
	speed = power * 0.1;
}
