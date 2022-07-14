#pragma once

struct ObbDesc
{
	Vector2 position;
	Vector2 up;
	Vector2 right;

	float   width;
	float   height;
};

class ColliderBox : public Collider
{
public:
	ColliderBox(Vector2 size);
	ColliderBox(Vector2 size, Transform* target);
	~ColliderBox();

	void Update() override;

	bool Collision(Vector2 position)   override;
	bool Collision(ColliderBox* other) override;

	void SetOffset(Vector2 offset) override;

	void SetVertex();

	ObbDesc GetObb();

	float Left()   { return pos.x - size.x * 0.5f + offset.x;}
	float Right()  { return pos.x + size.x * 0.5f + offset.x;}
	float Top()    { return pos.y - size.y * 0.5f + offset.y;}
	float Bottom() { return pos.y + size.y * 0.5f + offset.y;}

private:
	Vector2 size;
};
