#include "Framework.h"
#include "Collision.h"
bool Collision::Collision(Rect* rect, Vector2 point)
{
	if
		(
			point.x > rect->Left() &&
			point.x < rect->Right() &&
			point.y > rect->Top() &&
			point.y < rect->Bottom()
			)
		return true;

	return false;
}

bool Collision::Collision(Vector2 point, Rect* rect)
{
	return Collision(rect, point);
}

bool Collision::Collision(Rect* r1, Rect* r2)
{
	if
		(
			r1->Right() > r2->Left() &&
			r1->Left() < r2->Right() &&
			r1->Bottom() > r2->Top() &&
			r1->Top() < r2->Bottom()
			)
		return true;

	return false;
}

bool Collision::Collision(Circle* circle, Vector2 point)
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

bool Collision::Collision(Vector2 point, Circle* circle)
{
	return Collision(circle, point);
}

bool Collision::Collision(Circle* c1, Circle* c2)
{
	if (c1->Radius() + c2->Radius() > Distance(c1->Pos(), c2->Pos()))
		return true;

	return false;
}

bool Collision::Collision(Circle* circle, Rect* rect)
{
	Vector2 center = circle->Pos();

	if
		(
			(center.x > rect->Left() && center.x < rect->Right()) ||
			(center.y > rect->Top() && center.y < rect->Bottom())
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

bool Collision::Collision(Rect* rect, Circle* circle)
{
	return Collision(circle, rect);
}

bool Collision::Collision(Line* line1, Line* line2)
{
	return line1->IsBetween(line2) && line2->IsBetween(line1);
}
