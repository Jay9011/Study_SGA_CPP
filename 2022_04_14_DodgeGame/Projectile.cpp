#include "Framework.h"
#include "Projectile.h"

Projectile::Projectile()
	: speed(10), obj(nullptr)
{
}

Projectile::Projectile(int speed)
	: speed(speed), obj(nullptr)
{
}

Projectile::~Projectile()
{
	if (obj)
	{
		delete obj;
	}
}

void Projectile::Update()
{
	obj->Pos().y += speed;
}
