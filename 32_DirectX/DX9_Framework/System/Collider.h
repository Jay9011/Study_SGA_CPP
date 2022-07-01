#pragma once
class Collider : public Transform
{
public:
	Collider();
	Collider(Transform* target);
	virtual ~Collider();

	virtual void Update();
	virtual void Render();

	virtual bool Collision(D3DXVECTOR2 position);

	virtual void SetOffset(D3DXVECTOR2 offset) { this->offset = offset; }

private:
	Transform* target;

protected:
	vector<VertexColor> vertices;
	D3DXVECTOR2 offset;	// 위치 보정을 위한 값


/*
*  Options
*/
private:
	static bool hiddenInGame;
public:
	static const bool& HiddenInGame() { return hiddenInGame = !hiddenInGame; }

};
