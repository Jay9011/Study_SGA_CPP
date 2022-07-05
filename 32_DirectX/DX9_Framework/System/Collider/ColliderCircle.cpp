#include "Framework.h"
#include "ColliderCircle.h"

ColliderCircle::ColliderCircle(float radius, Transform* target) :
	Collider(target)
	, radius(radius)
	, sectorCount(36)
{
	SetVertex();
}

ColliderCircle::~ColliderCircle() = default;

void ColliderCircle::Update()
{
	Collider::Update();
}

bool ColliderCircle::Collision(D3DXVECTOR2 position)
{
	float distance = Math::Distance(this->pos, position);

	if (distance < radius)
		return true;

	return false;
}

bool ColliderCircle::Collision(ColliderBox* rect)
{
	D3DXVECTOR2 center = this->pos;

	if ((center.x > rect->Left() && center.x < rect->Right())
		|| (center.y > rect->Top() && center.y < rect->Bottom()))
	{
		ColliderBox cRect({ this->radius * 2, this->radius * 2 });
		cRect.pos = center;

		cRect.UpdateWorld();
		cRect.SetWorld();

		return cRect.Collision(rect);
	}
	else
	{
		D3DXVECTOR2 edges[4];

		edges[0] = { rect->Left() , rect->Top() };
		edges[1] = { rect->Right(), rect->Top() };
		edges[2] = { rect->Left() , rect->Bottom() };
		edges[3] = { rect->Right(), rect->Bottom() };

		for (size_t i = 0; i < 4; i++)
		{
			if (Collision(edges[i]))
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

	for (size_t i = 0; i < sectorCount + 1; i++)
	{
		D3DXVECTOR2 pos;
		pos.x =  sin((double)angle * i) * radius;
		pos.y = -cos((double)angle * i) * radius;

		vertices.push_back(VertexColor(pos.x + offset.x, pos.y + offset.y, 0xFF00FF00));
	}
}

void ColliderCircle::SetOffset(D3DXVECTOR2 offset)
{
	Collider::SetOffset(offset);

	SetVertex();
}
