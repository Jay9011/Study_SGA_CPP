#pragma once

class Plane;

class Enemy
{
public:
	Enemy();
	Enemy(Vector2 _pos);
	~Enemy();

	void Update();
	void Render();

	void Move();
	void Shoot();

	bool& IsActive() { return isActive; }
	Rect* GetRect() { return rect; }

	void Collision(Plane* player);

	BulletManager* GetBulletManager() { return bullets; }

private:
	Texture* texture;
	Rect*	 rect;

	Vector2	 dir;
	double	 speed;

	POINT	 frame;

	bool	 isActive;

	double	 time;
	double	 randomTime;

	BulletManager* bullets;
};

