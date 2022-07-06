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
	void Jump();

private:
	vector<Animation*> actions;

	float speed;
	float jumpSpeed;

	bool isRight;
	bool isJump;

};
