#pragma once
class SGABall
{
public:
	SGABall();
	~SGABall();

	void Update();
	void Render(HDC hdc);

private:
	Circle* circle;

	double	speed;
	Vector2 dir;

	HBRUSH	whiteBrush;
};

