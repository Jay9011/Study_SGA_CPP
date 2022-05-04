#pragma once

#define	MAX_HP	5

enum class Direction
{
	LEFT,
	RIGHT,
	UP,
	DOWN,
	END
};

class SGABrick
{
public:
	SGABrick();
	SGABrick(Vector2 pos, Vector2 size, UINT hp);
	~SGABrick();

	void Render(HDC hdc);

	UINT GetHP() { return curHP; }

	Direction CollisionDir(Circle* circle);

private:
	Rect*	rect;
	UINT	curHP;

	HBRUSH	brushes[MAX_HP];
};
