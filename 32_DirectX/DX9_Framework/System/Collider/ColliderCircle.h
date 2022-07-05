#pragma once
class ColliderCircle : public Collider
{
public:
	ColliderCircle(float radius, Transform* target);
	~ColliderCircle();

	void Update() override;

	bool Collision(D3DXVECTOR2 position) override;
	bool Collision(ColliderBox* rect) override;
	bool Collision(ColliderCircle* circle) override;

	void SetVertex();
	void SetOffset(D3DXVECTOR2 offset) override;

private:
	float radius;

	UINT sectorCount;

};