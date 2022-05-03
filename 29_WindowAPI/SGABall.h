#pragma once
class SGABall
{
public:
	SGABall();
	~SGABall();

	void Update();
	void Render(HDC hdc);

	void SetBarRect(Rect* rect) { this->barRect = rect; };

	void CollisionBar();
	void CollisionWall();
	void CollisionBrick();

private:
	Circle* circle;

	double	speed;
	Vector2 dir;
	Vector2	initDir;

	HBRUSH	whiteBrush;

	bool	isPlay;

	Rect*	barRect;
};

