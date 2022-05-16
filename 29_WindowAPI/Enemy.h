#pragma once

class Enemy
{
public:
	Enemy();
	Enemy(Vector2 _pos);
	~Enemy();

	void Update();
	void Render();

private:
	Texture* texture;
	Rect*	 rect;

	double	 speed;

	POINT	 frame;

	bool	 isActive;

	double	 time;
	double	 randomTime;
};

