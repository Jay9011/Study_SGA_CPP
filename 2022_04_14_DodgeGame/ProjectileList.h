#pragma once

class ProjectileList
{
public:
	ProjectileList();
	~ProjectileList();

	void Update();
	void Render(HDC hdc);

	list<Projectile*> projectiles;
};