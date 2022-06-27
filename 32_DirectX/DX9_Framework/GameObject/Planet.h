#pragma once
class Planet : public Transform
{
public:
	Planet(D3DCOLOR color, float radius, float rotationSpeed, float revolutionSpeed, UINT sectorCount = 36);
	Planet(D3DCOLOR color, D3DCOLOR center_color, float radius, float rotationSpeed, float revolutionSpeed, UINT sectorCount = 36);
	~Planet();

	void Update();
	void Render();

	void UpdateWorld() override;

	void SetVerticesColor(size_t index, D3DCOLOR color) { if (index < vertices.size() - 1) vertices[index].color = color; }

private:
	vector<Vertex> vertices;

	float radius;
	float rotationSpeed;	// 자전 속도

	float revolutionAngle;	// 공전 각도
	float revolutionSpeed;	// 공전 속도

	UINT  sectorCount;

};
