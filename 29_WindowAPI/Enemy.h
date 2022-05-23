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
	void ChangeDirection();
	void Shoot();

	bool& IsActive() { return isActive; }
	Rect* GetRect() { return rect; }
	
	void SetHp(int _hp) { hp = _hp; }

	void GetPlayer(Plane* player);
	void Collision(Plane* player);

	BulletManager* GetBulletManager() { return bullets; }

	void SetTarget(Plane* player);
	void SetTargetDir(Vector2 _dir) { this->targetDir = _dir; }

private:
	Texture* texture;
	Rect*	 rect;

	Vector2	 dir;
	double	 speed;
	int		 hp;

	POINT	 frame;

	bool	 isActive;

	double	 time;
	double	 randomTime;

	BulletManager* bullets;
	Vector2 targetDir;
};

