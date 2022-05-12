#include "Framework.h"
#include "Tank.h"

Tank::Tank()
	: angle(0), speed(5), barrelLength(200), power(3), deltaPower(3), isCharging(false)
{
	body	= new Circle(Vector2(200, 500), 100);
	barrel  = new Line(body->Pos(), Vector2( 0, 0));

	//cannonBall = new CannonBall();
	cbManager = new CannonBallManager(100);

	powerBarFront = new Rect(50, 650, 50            , 700);
	powerBarBack  = new Rect(50, 650, 50 + MAX_POWER, 700);

	   grayBrush = CreateSolidBrush(COLOR_GRAY);
	magentaBrush = CreateSolidBrush(COLOR_MAGENTA);
}

Tank::~Tank()
{
	delete barrel;
	delete body;
	//delete cannonBall;
	delete cbManager;
	
	DeleteObject(   grayBrush);
	DeleteObject(magentaBrush);
}

void Tank::Update()
{
	/*if (GetAsyncKeyState(VK_UP))
		angle += 0.05;
	else if (GetAsyncKeyState(VK_DOWN))
		angle -= 0.05;*/

	// 마우스 위치로 각도 찾아서 포신 이동시키기
	/*Vector2 temp = mousePos - body->Pos();
	angle = atan2(-temp.y, temp.x);
	barrel->End().x =  cos(angle) * barrelLength + body->Pos().x;
	barrel->End().y = -sin(angle) * barrelLength + body->Pos().y;*/

	Vector2 dir = mousePos - body->Pos();
	dir.Normalize();

	barrel->End() = body->Pos() + dir * barrelLength;
	barrel->Start() = body->Pos();

	if (GetAsyncKeyState(VK_LEFT))
	{
		//body->Pos().x -= speed;
		body->Pos() += Vector2(-1, 0) * speed;

		//if (body->Left() < 0)
		//{
		//	body->Pos().x = body->Radius();
		//}
		if (body->Pos().x < barrelLength)
		{
			body->Pos().x = barrelLength;
		}
	}
	else if (GetAsyncKeyState(VK_RIGHT))
	{
		//body->Pos().x += speed;
		body->Pos() += Vector2(1, 0) * speed;

		//if (body->Right() > WIN_WIDTH)
		//{
		//	body->Pos().x = WIN_WIDTH - body->Radius();
		//}
		if (body->Pos().x > WIN_WIDTH - barrelLength)
		{
			body->Pos().x = WIN_WIDTH - barrelLength;
		}
	}

	if (GetAsyncKeyState(VK_SPACE))
	{
		isCharging = true;
		power += deltaPower;

		if (power > MAX_POWER)
			power = MAX_POWER;

		powerBarFront->SetRect(powerBarFront->  Left()        , 
			                   powerBarFront->   Top()        , 
			                   powerBarFront->  Left() + power,	// 파워 만큼 길이를 늘린다.
			                   powerBarFront->Bottom()        );
	}
	else if (isCharging)
	{
		isCharging = false;
		//cannonBall->Fire(barrel->End(), angle, power);
		//cbManager->Fire(barrel->End(), angle, power);
		cbManager->Fire(barrel->End(), dir, power);
		power = 3;
	}

	//cannonBall->Update();
	cbManager->Update();
}

void Tank::Render(HDC hdc)
{
	SelectObject(hdc, oldBrush);
	body->Render(hdc);
	barrel->Render(hdc);
	//cannonBall->Render(hdc);
	cbManager->Render(hdc);

	oldBrush = (HBRUSH)SelectObject(hdc, grayBrush);
	powerBarBack->Render(hdc);
	SelectObject(hdc, oldBrush);

	oldBrush = (HBRUSH)SelectObject(hdc, magentaBrush);
	powerBarFront->Render(hdc);
	SelectObject(hdc, oldBrush);

	wstring str = L"";

	str += L"Angle : ";
	str += to_wstring(RadianToDegree(angle));

	TextOut(hdc, 0, 0, str.c_str(), str.length());

	str = L"";
	str += L"MousePos: ";
	str += to_wstring(mousePos.x);
	str += L" , ";
	str += to_wstring(mousePos.y);

	TextOut(hdc, 0, 20, str.c_str(), str.length());
}
