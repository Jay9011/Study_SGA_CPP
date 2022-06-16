#pragma once
class Missile : public Object
{
public:
	Missile();
	~Missile();

	void Update();
	void Render();

private:
	double speed;
	double angle;

	Animation* animation;
	
};