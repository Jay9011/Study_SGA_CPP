#pragma once
class Plane
{
public:
	Plane();
	~Plane();

	void Update();
	void Render();

	void Move();

private:
	Texture* texture;
	Rect*	 rect;

	double	 speed;

};

