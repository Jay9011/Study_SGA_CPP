#pragma once
class CannonBall
{
public:
	CannonBall();
	~CannonBall();

	void Update();
	void Render(HDC hdc);

	bool IsFire() { return isFire; }
	void Fire(Vector2 pos, double angle, double power);

private:
	Circle* ball;

	double angle;
	double speed;

	bool isFire;

	double gravity;
};
