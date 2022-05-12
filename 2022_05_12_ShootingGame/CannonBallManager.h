#pragma once
class CannonBallManager
{
public:
	CannonBallManager(UINT poolCount);
	~CannonBallManager();

	void Update();
	void Render(HDC hdc);

	void Fire(Vector2 pos, double angle, double power);
	void Fire(Vector2 pos, Vector2 dir , double power);

private:
	vector<CannonBall*> cannonBalls;

};

