#pragma once
class ColliderBox;
class ColliderCircle;
class Collider : public Transform
{
public:
	Collider();
	Collider(Transform* target);
	virtual ~Collider();

	virtual void Update();
	virtual void Render();

	virtual bool Collision(D3DXVECTOR2 position);
	virtual bool Collision(ColliderBox* other);
	virtual bool Collision(ColliderCircle* other);

	virtual void SetOffset(D3DXVECTOR2 offset) { this->offset = offset; }

	function<void()>& HitEvent() { return hitEvent; }

	bool& IsActive() { return isActive; }

protected:
	bool isActive;

	Transform* target;
	vector<VertexColor> vertices;
	D3DXVECTOR2 offset;	// 위치 보정을 위한 값
	function<void()> hitEvent;


/*
*  Options
*/
protected:
	static bool hiddenInGame;
public:
	static const bool& HiddenInGame() { return hiddenInGame = !hiddenInGame; }

};
