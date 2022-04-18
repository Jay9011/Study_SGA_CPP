#pragma once

class Projectile
{
public:
	Projectile();
	Projectile(int speed);
	~Projectile();

	Object* GetObj()				{ return obj; }
	void	SetObj(Object* _object) { obj = _object; }

	void	Delete() { if (obj) delete obj; }

	void	Update();

private:
	Object*	obj;
	int		speed;
};
