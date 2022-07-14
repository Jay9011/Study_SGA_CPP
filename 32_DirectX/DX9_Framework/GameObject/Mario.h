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

	void SetAnimation();
	void SetAction(State state);

	void Damage();

	Collider* GetCollider() { return collider; }

private:
	vector<Animation*> actions;

	float speed;
	float jumpSpeed;

	bool isRight;
	bool isJump;

	Texture*  weaponTex;
	Transform weaponTrans;

	bool isPlayer;

	Collider* collider;
	
	//MultiShader
	Texture* rainbow;

	Shader*  marioShader;
	Shader* weaponShader;

	D3DXCOLOR color;
};
