#pragma once
class Plane
{
public:
	Plane();
	~Plane();

	void Update();
	void Render();

	void Move();

	void Collision(EnemyManager* enemies);

private:
	Texture* texture;
	Rect*	 rect;

	double	 speed;

};

