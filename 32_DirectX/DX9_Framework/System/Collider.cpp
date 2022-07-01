#include "Framework.h"
#include "Collider.h"

bool Collider::hiddenInGame = false;

Collider::Collider() :
	Collider(nullptr)
{}

Collider::Collider(Transform* target) :
	target(target)
	, offset(0, 0)
{
}

Collider::~Collider()
{
}

void Collider::Update()
{
	this->pos = target->pos + offset;

	UpdateWorld();
}

void Collider::Render()
{
	if (hiddenInGame)
		return;

	DEVICE->SetFVF(VertexColor::fvf);

	SetWorld();

	DEVICE->DrawPrimitiveUP(D3DPT_LINESTRIP, vertices.size() - 1, vertices.data(), sizeof(VertexColor));
}

bool Collider::Collision(D3DXVECTOR2 position)
{
	return false;
}
