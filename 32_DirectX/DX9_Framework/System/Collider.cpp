#include "Framework.h"
#include "Collider.h"

bool Collider::hiddenInGame = false;

Collider::Collider() :
	Collider(nullptr)
{}

Collider::Collider(Transform* target) :
	target(target)
	, offset(0, 0)
	, isActive(true)
{
}

Collider::~Collider()
{
}

void Collider::Update()
{
	if (!isActive)
		return;

	if (target != nullptr)
		this->pos = target->pos + offset;

	UpdateWorld();
}

void Collider::Render()
{
	if (!isActive)
		return;

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

bool Collider::Collision(ColliderBox* other)
{
	return false;
}

bool Collider::Collision(ColliderCircle* other)
{
	return false;
}
// dynamic_cast : DownCasting을 하는 명령어, 다운캐스팅 실패 시 nullptr 반환
bool Collider::Collision(Collider* other)
{
	if (!isActive)
		return false;

	ColliderBox* box = dynamic_cast<ColliderBox*>(other);
	if (box != nullptr)
		return Collision(box);

	ColliderCircle* circle = dynamic_cast<ColliderCircle*>(other);
	if (circle != nullptr)
		return Collision(circle);

	return false;
}
