#pragma once
class Plane
{
public:
	Plane();
	~Plane();

	void Update();
	void Render();

	void Move();
	void Shoot();

	void Collision(EnemyManager* enemies);

	Rect* GetRect() { return rect; }
	BulletManager* GetBulletManager() { return bullets; }

private:
	Texture* texture;
	Rect*	 rect;

	double	 speed;

	BulletManager* bullets;
};

