#pragma once
class Knight
{
	enum STATE
	{
		ATTACK,
		BLOCK,
		CAST,
		CROUCH,
		DASH,
		IDLE = 8,
		WALK = 12,
	} state;

public:
	Knight();
	~Knight();

	void Update();
	void Render();

	void LoadXML(string file);

	void PlayAction();
	void PlayAction(STATE state);

	void SetIDLE() { PlayAction(IDLE); }

private:
	Texture* texture;
	vector<Animation*> actions;

	Rect* rect;

	int curAction;

	double speed;

	Texture* land;

	CannonBallManager* cannonBalls;
};

