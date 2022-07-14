#pragma once

class Planet : public Transform
{
public:
	Planet(D3DCOLOR color, float radius, float rotationSpeed, float revolutionSpeed, UINT sectorCount = 36);
	~Planet();

	void Update();
	void Render();

	void UpdateWorld() override;

private:
	vector<VertexColor> vertices;

	float radius;
	float rotationSpeed;   //자전 속도

	float revolutionAngle; //공전 각도
	float revolutionSpeed; //공전 속도

	UINT sectorCount;
};
