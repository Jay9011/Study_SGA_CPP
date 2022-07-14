#include "Framework.h"
#include "ColliderBox.h"

ColliderBox::ColliderBox(Vector2 size)
	:size(size)
{
	SetVertex();
}

ColliderBox::ColliderBox(Vector2 size, Transform* target)
	: size(size), Collider(target)
{
	SetVertex();
}

ColliderBox::~ColliderBox()
{
}

void ColliderBox::Update()
{
	if (target != nullptr)
		this->angle = target->angle;

	Collider::Update();
}

bool ColliderBox::Collision(Vector2 position)
{
	if (!isActive)
		return false;

	if (
		position.x > Left()  &&
		position.x < Right() &&
		position.y > Top()   &&
		position.y < Bottom()
		)
		return true;

	return false;
}

bool ColliderBox::Collision(ColliderBox* other)
{
	if (!isActive)
		return false;

	ObbDesc rThis  =  this->GetObb();
	ObbDesc rOther = other->GetObb();

	Vector2 distance = rThis.position - rOther.position;

	Vector2 axes[4] =
	{
		 rThis.right,
		 rThis.up,
		rOther.right,
		rOther.up
	};

	Vector2 vectors[4] = 
	{
		axes[0] *  rThis.width,
		axes[1] *  rThis.height,
		axes[2] * rOther.width,
		axes[3] * rOther.height,
	};

	//도형별로
	for (UINT i = 0; i < 4; i++)
	{
		float sum = 0;

		//축 별로
		for (UINT j = 0; j < 4; j++)
		{
			sum += abs(D3DXVec2Dot(&axes[i], &vectors[j]));
		}

		if (sum <  abs(D3DXVec2Dot(&axes[i], &distance)))
			return false;
	}

	return true;
}

void ColliderBox::SetOffset(Vector2 offset)
{
	Collider::SetOffset(offset);

	SetVertex();
}

void ColliderBox::SetVertex()
{
	vertices.clear();

	vertices.push_back(VertexColor(-size.x * 0.5f + offset.x, -size.y * 0.5f + offset.y, 0xFF00FF00));
	vertices.push_back(VertexColor(+size.x * 0.5f + offset.x, -size.y * 0.5f + offset.y, 0xFF00FF00));
	vertices.push_back(VertexColor(+size.x * 0.5f + offset.x, +size.y * 0.5f + offset.y, 0xFF00FF00));
	vertices.push_back(VertexColor(-size.x * 0.5f + offset.x, +size.y * 0.5f + offset.y, 0xFF00FF00));
	vertices.push_back(VertexColor(-size.x * 0.5f + offset.x, -size.y * 0.5f + offset.y, 0xFF00FF00));
}

ObbDesc ColliderBox::GetObb()
{
	ObbDesc desc;

	//desc.position = this->pos + this->offset;
	D3DXVec2TransformCoord(&desc.position, &offset, &world);

	desc.right = { this->world._11, this->world._12 };
	desc.up    = { this->world._21, this->world._22 };

	D3DXVec2Normalize(&desc.right, &desc.right);
	D3DXVec2Normalize(&desc.up   , &desc.up   );

	desc.width  = this->size.x * 0.5f;
	desc.height = this->size.y * 0.5f;

	return desc;
}
