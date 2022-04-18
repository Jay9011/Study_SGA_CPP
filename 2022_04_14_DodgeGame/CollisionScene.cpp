#include "Framework.h"
#include "CollisionScene.h"

CollisionScene::CollisionScene()
	: speed(10), gameover(false)
{
	player = new Circle({ 500, 800 }, 50);
	projectiles = new ProjectileList();

	  redBrush = CreateSolidBrush(COLOR_RED);
	greenBrush = CreateSolidBrush(COLOR_GREEN);
	 blueBrush = CreateSolidBrush(COLOR_BLUE);
}

CollisionScene::~CollisionScene()
{
	delete projectiles;
	delete player;

	DeleteObject(redBrush);
	DeleteObject(greenBrush);
	DeleteObject(blueBrush);
}

void CollisionScene::Update()
{
	if (!gameover)
	{
		if (GetAsyncKeyState(VK_LEFT))
		{
			if (player->Left() > 0)
			{
				player->Pos().x -= speed;
			}
		}
		if (GetAsyncKeyState(VK_RIGHT))
		{
			if (player->Right() < 1500)
			{
				player->Pos().x += speed;
			}
		}

		projectiles->Update();
	}
}

void CollisionScene::Render(HDC hdc)
{
	SelectObject(hdc, blueBrush);
	player->Render(hdc);
	
	SelectObject(hdc, redBrush);
	projectiles->Render(hdc);

	for (Projectile* item : projectiles->projectiles)
	{
		Rect* rect = dynamic_cast<Rect*>(item->GetObj());
		if (rect)
		{
			// rect인 경우
			if (Collision(player, rect))
			{
				gameover = true;
				break;
			}
		}
		else
		{
			// rect가 아닌 경우
			Circle* circle = dynamic_cast<Circle*>(item->GetObj());
			if (circle)
			{
				if (Collision(player, circle))
				{
					gameover = true;
					break;
				}
			}
		}
	}

	if (gameover)
	{
		wstring str = L"Game Over ! ! !";
		for (int i = 0; i < 30; i++)
		{
			TextOut(hdc, (i * 50), (i * 30), str.c_str(), str.size());
		}
	}
}

bool CollisionScene::Collision(Rect* rect, Point point)
{
	if (point.x > rect->Left()	&&
		point.x < rect->Right() && 
		point.y > rect->Top()	&&
		point.y < rect->Bottom())
	{
		return true;
	}

	return false;
}

bool CollisionScene::Collision(Rect* r1, Rect* r2)
{
	if (r1->Right()	 > r2->Left()	&&
		r1->Left()	 < r2->Right()	&&
		r1->Bottom() > r2->Top()	&&
		r1->Top()	 < r2->Bottom())
	{
		return true;
	}

	return false;
}

bool CollisionScene::Collision(Circle* circle, Point point)
{
	double distance = Math::Distance(circle->Pos(), point);

	if (circle->Radius() > distance)
	{
		return true;
	}

	return false;
}

bool CollisionScene::Collision(Circle* c1, Circle* c2)
{
	if (c1->Radius() + c2->Radius() > Math::Distance(c1->Pos(), c2->Pos()))
	{
		return true;
	}
	return false;
}

bool CollisionScene::Collision(Circle* circle, Rect* rect)
{
	Point center = circle->Pos();

	if (// 사각형과 원 외곽 사각형 충돌과 원의 충돌이 같을 때
		(center.x > rect->Left() && center.x < rect->Right())	||
		(center.y > rect->Top()	 && center.y < rect->Bottom())
		)
	{
		// 원 외곽 사각형을 임시로 만들어서
		Rect cRect(center, { circle->Radius() * 2, circle->Radius() * 2 });
		// 충돌 검사를 한다.
		return Collision(&cRect, rect);
	}
	else
	{
		// 대각선의 방향일 때, 점과 원의 충돌로 본다.
		Point edges[4];

		edges[0] = { rect->Left() ,	rect->Top() };
		edges[1] = { rect->Right(), rect->Top() };
		edges[2] = { rect->Left() ,	rect->Bottom() };
		edges[3] = { rect->Right(), rect->Bottom() };

		for (size_t i = 0; i < 4; i++)
		{
			if (Collision(circle, edges[i]))
			{
				return true;
			}
		}
	}

	return false;
}
