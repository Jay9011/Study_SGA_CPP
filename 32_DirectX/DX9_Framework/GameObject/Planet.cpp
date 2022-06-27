#include "Framework.h"
#include "Planet.h"

Planet::Planet(D3DCOLOR color, float radius, float rotationSpeed, float revolutionSpeed, UINT sectorCount) :
	Planet(color, color, radius, rotationSpeed, revolutionSpeed, sectorCount)
{
	
}

Planet::Planet(D3DCOLOR color, D3DCOLOR center_color, float radius, float rotationSpeed, float revolutionSpeed, UINT sectorCount) :
	radius(radius),
	rotationSpeed(rotationSpeed),
	revolutionAngle(0),
	revolutionSpeed(revolutionSpeed),
	sectorCount(sectorCount)
{
	vector<Vertex> circle;
	circle.push_back(Vertex(0, 0, center_color));

	float angle_size = 2.f * PI / sectorCount;

	// 각 점들의 위치를 저장
	for (size_t i = 0; i < sectorCount; i++)
	{
		float a = angle_size * i;

		Vector2 p;
		p.x = cos(a) * radius;
		p.y = -sin(a) * radius;

		circle.push_back(Vertex(p.x, p.y, color));
	}
	// Triangle List 를 작성
	for (size_t i = 0; i < sectorCount; i++)
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

	DEVICE->SetFVF(Vertex::fvf);
	DEVICE->DrawPrimitiveUP(D3DPT_TRIANGLELIST, sectorCount, vertices.data(), sizeof(Vertex));
}

void Planet::UpdateWorld()
{
	Transform::UpdateWorld();
}
