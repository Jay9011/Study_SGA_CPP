#pragma once
class CannonBall
{
public:
	CannonBall();
	~CannonBall();

	void Update();
	void Render(HDC hdc);

	void Fire(Point pos, double angle, double power);

private:
	Circle* ball;

	double angle;
	double speed;

	bool isFire;

	double gravity;
};
