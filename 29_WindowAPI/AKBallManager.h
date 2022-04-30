#pragma once
class AKBallManager
{
public:
	AKBallManager(UINT poolCount);
	~AKBallManager();

private:
	vector<AKBall*> arkanoidBalls;

public:
	void Update();
	void Render(HDC hdc);

	bool	GetReady();
	AKBall*	SetReady(Vector2 pos);
	void	Fire(Vector2 dir);
	void	Fire(Vector2 pos, Vector2 dir);

	vector<AKBall*>	Balls();
};

