#pragma once
class Mario
{
	enum State
	{
		IDLE_L,
		IDLE_R,
		RUN_L,
		RUN_R,
		JUMP_L,
		JUMP_R,
		ATK_L,
		ATK_R,
		SPIN_L,
		SPIN_R
	} state;

public:
	Mario();
	Mario(Landscape* landscape);
	~Mario();

	void Update();
	void Render();

	void Move();
	void Attack();
	void Jump();

	void SetAction(int state);
	
	void AddAction();

	void SetIdle();
	void SetSpin(int isSpin) { this->isSpin = isSpin; }

	void Debug();
	
	void SetLandscape(Landscape* landscape) { this->landscape = landscape; }

private:
	Texture* texture;
	Rect* rect;

	vector<Animation*> actions;
	Animation* curAction;

	double	moveSpeed;

	bool	isJump;
	double	jumpSpeed;
	double	gravity;
	UINT	jumpCount;

	Landscape* landscape;

	bool	isSpin;
};

