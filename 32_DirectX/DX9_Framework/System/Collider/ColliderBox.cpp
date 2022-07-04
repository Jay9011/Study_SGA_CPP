#include "Framework.h"
#include "ColliderBox.h"

ColliderBox::ColliderBox() : 
	ColliderBox({0, 0}) 
{}

ColliderBox::ColliderBox(D3DXVECTOR2 size) : 
	ColliderBox(size, nullptr) 
{}

ColliderBox::ColliderBox(D3DXVECTOR2 size, Transform* target) :
	Collider(target)
	, size(size)
{
	SetVertex();
}

ColliderBox::~ColliderBox()
{
}

void ColliderBox::Update()
{
	this->angle = target->angle;

	Collider::Update();
}

bool ColliderBox::Collision(D3DXVECTOR2 position)
{
	if (
		position.x > Left()  &&
		position.x < Right() &&
		position.y > Top()   &&
		position.y < Bottom()
		)
	{
		return true;
	}
	return false;
}

bool ColliderBox::Collision(ColliderBox* other)
{
	OBBDesc rThis  =  this->GetOBB();
	OBBDesc rOther = other->GetOBB();

	D3DXVECTOR2 distance = rThis.position - rOther.position;
	D3DXVECTOR2 axes[4] =
	{
		rThis.up,
		rThis.right,
		rOther.up,
		rOther.right
	};

	D3DXVECTOR2 vectors[4] =
	{
		axes[0] * rThis.width,
		axes[1] * rThis.height,
		axes[2] * rOther.width,
		axes[3] * rOther.height,
	};

	// 도형별로
	for (size_t i = 0; i < 4; i++)
	{
		float sum = 0;
		
		// 축 별로
		for (size_t j = 0; j < 4; j++)
		{
			sum += abs(D3DXVec2Dot(&axes[i], &vectors[j]));
		}

		if (sum < abs(D3DXVec2Dot(&axes[i], &distance)))
			return false;
	}

	return true;
}

void ColliderBox::SetOffset(D3DXVECTOR2 offset)
{
	Collider::SetOffset(offset);

	SetVertex();
}

void ColliderBox::SetVertex()
{
	vertices.clear();

	vertices.push_back(VertexColor(-size.x * .5f + offset.x, -size.y * .5f + offset.y, 0xFF00FF00));
	vertices.push_back(VertexColor(+size.x * .5f + offset.x, -size.y * .5f + offset.y, 0xFF00FF00));
	vertices.push_back(VertexColor(+size.x * .5f + offset.x, +size.y * .5f + offset.y, 0xFF00FF00));
	vertices.push_back(VertexColor(-size.x * .5f + offset.x, +size.y * .5f + offset.y, 0xFF00FF00));
	vertices.push_back(VertexColor(-size.x * .5f + offset.x, -size.y * .5f + offset.y, 0xFF00FF00));
}

OBBDesc ColliderBox::GetOBB()
{
	OBBDesc desc;

	desc.position = this->pos + this->offset;
	
	desc.up    = { this->world._11, this->world._12 };
	desc.right = { this->world._21, this->world._22 };

	D3DXVec2Normalize(&desc.up   , &desc.up   );
	D3DXVec2Normalize(&desc.right, &desc.right);

	desc.width  = size.x * 0.5f;
	desc.height = size.y * 0.5f;

	return desc;
}
