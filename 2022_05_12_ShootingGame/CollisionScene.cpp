#include "Framework.h"
#include "CollisionScene.h"

CollisionScene::CollisionScene()
	:speed(5)
{
	rect1 = new Rect(100, 100, 200, 200);
	rect2 = new Rect(Vector2(300, 150), Vector2(100, 50));

	circle1 = new Circle(Vector2(300, 300), 50);
	circle2 = new Circle({ 500, 300 }, 50);

	line1 = new Line();
	line2 = new Line(Vector2(400, 100), Vector2(100, 400));

	  redBrush = CreateSolidBrush(COLOR_RED);
	greenBrush = CreateSolidBrush(COLOR_GREEN);
	 blueBrush = CreateSolidBrush(COLOR_BLUE);

	   redPen  = CreatePen(PS_SOLID, 2, COLOR_RED);
	 greenPen  = CreatePen(PS_SOLID, 2, COLOR_GREEN);
}

CollisionScene::~CollisionScene()
{
	delete rect1;
	delete rect2;

	delete circle1;
	delete circle2;

	delete line1;
	delete line2;

	DeleteObject(  redBrush);
	DeleteObject(greenBrush);
	DeleteObject( blueBrush);
}

void CollisionScene::Update()
{
	if (GetAsyncKeyState(VK_LEFT))
	{
		rect1->Pos().x -= speed;
	}
	if (GetAsyncKeyState(VK_RIGHT))
	{
		rect1->Pos().x += speed;
	}
	if (GetAsyncKeyState(VK_UP))
	{
		rect1->Pos().y -= speed;
	}
	if (GetAsyncKeyState(VK_DOWN))
	{
		rect1->Pos().y += speed;
	}

	//circle1->Pos() = mousePos;

	line1->End() = mousePos;

}

void CollisionScene::Render(HDC hdc)
{
	//Rect
	/*if (Collision(rect1, mousePos))
	{
		SelectObject(hdc,  redBrush);
	}
	else
		SelectObject(hdc, greenBrush);*/

	/*if (Collision(rect1, rect2))
	{
		SelectObject(hdc, redBrush);
	}
	else
		SelectObject(hdc, greenBrush);*/
	
	rect1->Render(hdc);
	rect2->Render(hdc);
		
	//Circle
	if (Collision(circle1, rect1))
	{
		SelectObject(hdc, redBrush);
	}
	else
		SelectObject(hdc, greenBrush);

	circle1->Render(hdc);
	circle2->Render(hdc);

	// Line
	if (Collision(line1, line2))
		SelectObject(hdc, redPen);
	else
		SelectObject(hdc, greenPen);

	line1->Render(hdc);
	line2->Render(hdc);
}

bool CollisionScene::Collision(Rect* rect, Vector2 point)
{
	if 
	(
		point.x > rect->Left()  &&
		point.x < rect->Right() &&
		point.y > rect->Top()   &&
		point.y < rect->Bottom()
	)
		return true;

	return false;
}

bool CollisionScene::Collision(Rect* r1, Rect* r2)
{
	if 
	(
		r1->Right()  > r2->Left()  &&
		r1->Left()   < r2->Right() &&
		r1->Bottom() > r2->Top()   &&
		r1->Top()    < r2->Bottom()
	)
		return true;

	return false;
}

bool CollisionScene::Collision(Circle* circle, Vector2 point)
{
	/*double distance;

	double x = circle->Pos().x - point.x;
	double y = circle->Pos().y - point.y;

	distance = sqrt(x * x + y * y);*/

	double distance = Distance(circle->Pos(), point);

	if (circle->Radius() > distance)
		return true;

	return false;
}

bool CollisionScene::Collision(Circle* c1, Circle* c2)
{
	if (c1->Radius() + c2->Radius() > Distance(c1->Pos(), c2->Pos()))
		return true;

	return false;
}

bool CollisionScene::Collision(Circle* circle, Rect* rect)
{
	Vector2 center = circle->Pos();

	if
	(
		(center.x > rect->Left() && center.x < rect->Right() ) ||
		(center.y > rect->Top()  && center.y < rect->Bottom())
	)
	{
		Rect cRect(center, { circle->Radius() * 2 , circle->Radius() * 2 });

		return Collision(&cRect, rect);
	}
	else
	{
		Vector2 edges[4];

		edges[0] = { rect->Left(),  rect->Top() };
		edges[1] = { rect->Right(), rect->Top() }; 
		edges[2] = { rect->Left(),  rect->Bottom() }; 
		edges[3] = { rect->Right(), rect->Bottom() }; 

		for (UINT i = 0; i < 4; i++)
		{
			if (Collision(circle, edges[i]))
				return true;
		}
	}

	return false;
}

bool CollisionScene::Collision(Line* line1, Line* line2)
{
	return line1->IsBetween(line2) && line2->IsBetween(line1);
}
