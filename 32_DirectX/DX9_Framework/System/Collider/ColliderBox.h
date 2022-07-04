#pragma once

struct OBBDesc
{
	D3DXVECTOR2 position;
	D3DXVECTOR2 up;
	D3DXVECTOR2 right;

	float width;
	float height;
};

class ColliderBox : public Collider
{
public:
	ColliderBox();
	ColliderBox(D3DXVECTOR2 size);
	ColliderBox(D3DXVECTOR2 size, Transform* target);
	~ColliderBox();

	void Update() override;

	bool Collision(D3DXVECTOR2 position) override;
	bool Collision(ColliderBox* other) override;

	void SetOffset(D3DXVECTOR2 offset) override;
	void SetVertex();

	OBBDesc GetOBB();

	float Left()   { return pos.x - size.x * .5f + offset.x; }
	float Right()  { return pos.x + size.x * .5f + offset.x; }
	float Top()    { return pos.y - size.y * .5f + offset.y; }
	float Bottom() { return pos.y + size.y * .5f + offset.y; }

private:
	D3DXVECTOR2 size;

};
