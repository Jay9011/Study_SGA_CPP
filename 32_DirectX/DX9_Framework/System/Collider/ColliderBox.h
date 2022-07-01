#pragma once
class ColliderBox : public Collider
{
public:
	ColliderBox();
	ColliderBox(D3DXVECTOR2 size);
	ColliderBox(D3DXVECTOR2 size, Transform* target);
	~ColliderBox();

	void Update() override;

	bool Collision(D3DXVECTOR2 position) override;

	void SetOffset(D3DXVECTOR2 offset) override;
	void SetVertex();

	float Left()   { return pos.x - size.x * .5f + offset.x; }
	float Right()  { return pos.x + size.x * .5f + offset.x; }
	float Top()    { return pos.y - size.y * .5f + offset.y; }
	float Bottom() { return pos.y + size.y * .5f + offset.y; }

private:
	D3DXVECTOR2 size;

};
