#pragma once

class ColliderCircle : public Collider
{
public:
	ColliderCircle(float radius, Transform* target);
	~ColliderCircle();

	void Update() override;

	bool Collision(Vector2 position) override;
	bool Collision(ColliderBox* rect) override;
	bool Collision(ColliderCircle* circle) override;

	void SetVertex();
	void SetOffset(Vector2 offset) override;

private:
	float radius;

	UINT sectorCount;
};
