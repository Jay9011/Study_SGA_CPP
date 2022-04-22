#include "Framework.h"
#include "Tank.h"

Tank::Tank()
	: angle(0), speed(5), barrelLength(200), power(3), deltaPower(0.3), isPush(false)
{
	body	= new Circle(Point(200, 500), 100);
	barrel  = new Line( body->Pos(), Point( 0, 0));

	cannonBall = new CannonBall();
}

Tank::~Tank()
{
	delete cannonBall;
	delete barrel;
	delete body;
}

void Tank::Update()
{
	if (GetAsyncKeyState(VK_UP))
		angle += 0.05;
	else if (GetAsyncKeyState(VK_DOWN))
		angle -= 0.05;
	
	if (GetAsyncKeyState(VK_LEFT))
		body->Pos().x -= speed;
	else if (GetAsyncKeyState(VK_RIGHT))
		body->Pos().x += speed;

	if (GetAsyncKeyState(VK_SPACE))
	{
		isPush = true;
		power += deltaPower;
	}
	else if (isPush)
	{
		isPush = false;
		cannonBall->Fire(barrel->End(), angle, power);
		power = 3;
	}

	barrel->Start() = body->Pos();
	barrel->End().x =  cos(angle) * barrelLength + body->Pos().x;
	barrel->End().y = -sin(angle) * barrelLength + body->Pos().y;

	cannonBall->Update();
}

void Tank::Render(HDC hdc)
{
	body->Render(hdc);
	barrel->Render(hdc);
	cannonBall->Render(hdc);
}
