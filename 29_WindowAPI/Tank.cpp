#include "Framework.h"
#include "Tank.h"

Tank::Tank()
	: angle(0), barrelLength(200)
{
	body	= new Circle(Point(200, 500), 100);
	barrel  = new Line( body->Pos(), 
						Point( cos(angle) * barrelLength + body->Pos().x, 
							  -sin(angle) * barrelLength + body->Pos().y));
}

Tank::~Tank()
{
	delete body;
	delete barrel;
}

void Tank::Update()
{
	if (GetAsyncKeyState(VK_UP))
		angle += 0.05;
	else if (GetAsyncKeyState(VK_DOWN))
		angle -= 0.05;

	barrel->End().x =  cos(angle) * barrelLength + body->Pos().x;
	barrel->End().y = -sin(angle) * barrelLength + body->Pos().y;
}

void Tank::Render(HDC hdc)
{
	body->Render(hdc);
	barrel->Render(hdc);
}
