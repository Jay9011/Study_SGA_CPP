#include "Framework.h"
#include "Planet.h"

Planet::Planet(D3DCOLOR color, float radius, float rotationSpeed, float revolutionSpeed, UINT sectorCount)
	: radius(radius), rotationSpeed(rotationSpeed), revolutionSpeed(revolutionSpeed), sectorCount(sectorCount), revolutionAngle(0)
{
	vector<VertexColor> circle;
	circle.push_back(VertexColor(0, 0, color));

	for (UINT i = 0; i < sectorCount; i++)
	{
		float a = PI * 2.0f / sectorCount * i;

		Vector2 p;
		p.x =  cos(a) * radius;
		p.y = -sin(a) * radius;
		
		circle.push_back(VertexColor(p.x, p.y, color));
	}

	for (UINT i = 0; i < sectorCount; i++)
	{
		vertices.push_back(circle[0]);

		if (i == sectorCount - 1)
		{
			vertices.push_back(circle[1]);
			vertices.push_back(circle[circle.size() - 1]);
			break;
		}

		vertices.push_back(circle[i + 2]);
		vertices.push_back(circle[i + 1]);
	}
}

Planet::~Planet()
{
}

void Planet::Update()
{
	          angle += rotationSpeed;
	revolutionAngle += revolutionSpeed;

	UpdateWorld();
}

void Planet::Render()
{
	SetWorld();

	DEVICE->SetFVF(VertexColor::fvf);
	DEVICE->DrawPrimitiveUP(D3DPT_TRIANGLELIST, sectorCount, vertices.data(), sizeof(VertexColor));
}

void Planet::UpdateWorld()
{
	Transform::UpdateWorld();

	if (parent != nullptr)
	{
		Matrix revolution;
		D3DXMatrixRotationZ(&revolution, revolutionAngle);

		Matrix pTranslation;
		//D3DXMatrixIdentity(&pTranslation);
		//pTranslation._41 = parent->GetWorld()->_41;
		//pTranslation._42 = parent->GetWorld()->_42;
		D3DXMatrixTranslation
		(
			&pTranslation, 
			parent->GetWorld()->_41, 
			parent->GetWorld()->_42, 
			0.0f
		);


		//this->world *= *parent->GetWorld();
		
		this->world *= revolution * pTranslation;
	}
}
