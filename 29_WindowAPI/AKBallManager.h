#pragma once
class AKBallManager
{
public:
	AKBallManager(UINT poolCount);
	~AKBallManager();

public:
	vector<AKBall*> arkanoidBalls;

	void Update();
	void Render(HDC hdc);

	bool	ResetBall();
	bool	GetReady();
	AKBall*	SetReady(Vector2 pos);
	void	Fire(Vector2 dir);
	void	Fire(Vector2 pos, Vector2 dir);
};

