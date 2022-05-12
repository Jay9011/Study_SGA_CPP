#pragma once

class SGABrick;
class SGABrickManager;

class SGABall
{
public:
	SGABall();
	~SGABall();

	void Update();
	void Render(HDC hdc);

	void SetBarRect		(Rect* rect)			{ this->barRect = rect; }
	//void SetBrick		(SGABrick* brick)		{ this->brick = brick; }
	void SetBrickManager(SGABrickManager* bm)	{ this->bm = bm; }

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

	Rect*			 barRect;
	//SGABrick*		 brick;
	SGABrickManager* bm;
};

