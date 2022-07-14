#include "Framework.h"
#include "ColliderCircle.h"

ColliderCircle::ColliderCircle(float radius, Transform* target)
	:radius(radius), Collider(target), sectorCount(36)
{
	SetVertex();
}

ColliderCircle::~ColliderCircle()
{
}

void ColliderCircle::Update()
{
	Collider::Update();
}

bool ColliderCircle::Collision(Vector2 position)
{
	float distance = Math::Distance(this->pos, position);

	if (distance < radius)
		return true;

	return false;
}

bool ColliderCircle::Collision(ColliderBox* rect)
{
	Vector2 center = this->pos;

	if
		(
			(center.x > rect->Left() && center.x < rect->Right()) ||
			(center.y > rect->Top() && center.y < rect->Bottom())
			)
	{
		ColliderBox cRect({ this->radius * 2 , this->radius * 2 });
		cRect.pos = center;

		cRect.UpdateWorld();
		cRect.SetWorld();

		return rect->Collision(&cRect);
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
			if (this->Collision(edges[i]))
				return true;
		}
	}

	return false;
}

bool ColliderCircle::Collision(ColliderCircle* circle)
{
	if (this->radius + circle->radius > Math::Distance(this->pos, circle->pos))
		return true;

	return false;
}

void ColliderCircle::SetVertex()
{
	vertices.clear();

	float angle = PI * 2.0f / sectorCount;

	for (UINT i = 0; i <= sectorCount; i++)
	{
		Vector2 pos;
		pos.x =  sin(angle * i) * radius;
		pos.y = -cos(angle * i) * radius;

		vertices.push_back(VertexColor(pos.x + offset.x, pos.y + offset.y, 0xFF00FF00));
	}
}

void ColliderCircle::SetOffset(Vector2 offset)
{
	Collider::SetOffset(offset);

	SetVertex();
}
