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
