#pragma once
class CannonBallManager
{
public:
	CannonBallManager(UINT poolCount);
	~CannonBallManager();

	void Update();
	void Render(HDC hdc);

	void Fire(Point pos, double angle, double power);

private:
	vector<CannonBall*> cannonBalls;

};

