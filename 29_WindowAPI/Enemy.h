#pragma once

class Enemy
{
public:
	Enemy();
	Enemy(Vector2 _pos);
	~Enemy();

	void Update();
	void Render();

	bool& IsActive() { return isActive; }
	Rect* GetRect() { return rect; }

private:
	Texture* texture;
	Rect*	 rect;

	Vector2	 dir;
	double	 speed;

	POINT	 frame;

	bool	 isActive;

	double	 time;
	double	 randomTime;
};

