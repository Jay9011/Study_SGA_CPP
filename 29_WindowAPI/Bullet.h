#pragma once
class Bullet
{
public:
	Bullet();
	~Bullet();

	void Update();
	void Render();

	void Fire(Vector2 _pos, Vector2 _dir, double _speed);
	bool& IsFire() { return isFire; }
	Rect* GetRect() { return rect; }

private:
	Texture* texture;
	Rect*	 rect;

	double	speed;
	Vector2 dir;

	bool isFire;

};

