#pragma once
class Knight : public Transform
{
	enum State
	{
		IDLE,
		WALK,
		ATTACK
	} state;

public:
	Knight();
	~Knight();

	void Update();
	void Render();

	void Move();
	void Attack();
	void EndAttack();

	void LoadXML(string fileName, Type type, float speed = 0.1f);

	void SetAction(State state);

	void AddEnemy(Collider* collider) { enemies.push_back(collider); }

private:
	vector<Animation*> actions;

	float speed;

	bool isRight;
	bool isAttacking;

	Collider* weaponCollider;
	Vector2   weaponOffset;

	vector<Collider*> enemies;
};
