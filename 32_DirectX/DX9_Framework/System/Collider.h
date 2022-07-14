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

	virtual bool Collision(Vector2 position);
	virtual bool Collision(ColliderBox* other);
	virtual bool Collision(ColliderCircle* other);

	bool Collision(Collider* other);

	virtual void SetOffset(Vector2 offset) { this->offset = offset; }

	static void HiddenInGame() { hiddenInGame = !hiddenInGame; }

	function<void()>& HitEvent() { return hitEvent; }

	bool& IsActive() { return isActive; }

protected:
	Transform* target;

	vector<VertexColor> vertices;

	Vector2 offset; //��ġ ������ ���� ��

	static bool hiddenInGame;


	bool isActive;
	
public:
	function<void()> hitEvent;
};
