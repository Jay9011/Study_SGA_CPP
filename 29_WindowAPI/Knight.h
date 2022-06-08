#pragma once
class Knight
{
	enum STATE
	{
		ATTACK,
		BLOCK,
		CAST,
		CROUCH,
		DASH
	} state;

public:
	Knight();
	~Knight();

	void Update();
	void Render();

	void LoadXML(string file);

	void PlayAction();

private:
	Texture* texture;
	vector<Animation*> actions;

	Rect* rect;

	int curAction;
};

