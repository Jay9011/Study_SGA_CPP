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

