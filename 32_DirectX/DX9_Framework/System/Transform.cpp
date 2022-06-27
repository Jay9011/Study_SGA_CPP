#include "Framework.h"
#include "Transform.h"

Transform::Transform() : 
	pos(0, 0),
	scale(1, 1),
	angle(0),
	pivot(0, 0),
	parent(nullptr)
{
	D3DXMatrixIdentity(&S);
	D3DXMatrixIdentity(&R);
	D3DXMatrixIdentity(&T);
	D3DXMatrixIdentity(&world);
}

Transform::~Transform() = default;

void Transform::UpdateWorld()
{
	D3DXMatrixScaling(&S, scale.x, scale.y, 1.f);
	D3DXMatrixRotationZ(&R, angle);
	D3DXMatrixTranslation(&T, pos.x, pos.y, 0.f);

	Matrix P, IP;
	D3DXMatrixTranslation(&P, pivot.x, pivot.y, 0.f);
	D3DXMatrixInverse(&IP, nullptr, &P);

	world = IP * S * R * T * P;
}

void Transform::SetWorld()
{
	DEVICE->SetTransform(D3DTS_WORLD, &world);
}
