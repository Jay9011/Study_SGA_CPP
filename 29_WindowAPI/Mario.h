#pragma once
class Mario
{
	enum State
	{
		IDLE_L,
		IDLE_R,
		RUN_L,
		RUN_R
	} state;

public:
	Mario();
	~Mario();

	void Update();
	void Render();

	void Move();

	void SetAction(State state);
	
	void AddAction();

private:
	Texture* texture;
	Rect* rect;

	vector<Animation*> actions;
	Animation* curAction;

	double speed;

};

