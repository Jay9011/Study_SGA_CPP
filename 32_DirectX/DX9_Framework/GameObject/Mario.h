#pragma once
class Mario : public Transform
{
	enum State
	{
		IDLE,
		RUN,
		JUMP
	} state;

public:
	Mario();
	~Mario();

	void Update();
	void Render();

	void Move();
	void SetWeapon();
	void Damage();

	void SetAnimation();
	void SetAction(State state);

	Collider* GetCollider() { return collider; }

private:
	vector<Animation*> actions;

	float speed;
	float jumpSpeed;

	bool isPlayer;
	bool isRight;
	bool isJump;
	bool isDamagedAnimPlay;

	Texture*  weaponTexture;
	Transform weaponTrans;


	Collider* collider;
};
