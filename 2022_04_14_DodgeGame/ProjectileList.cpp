#include "Framework.h"
#include "ProjectileList.h"

ProjectileList::ProjectileList()
{
}

ProjectileList::~ProjectileList()
{
	for (Projectile* item : projectiles)
	{
		delete item;
	}
}

void ProjectileList::Update()
{
	static long oldTime = 0;
	static long timestack = 0;
	long curtime = clock();
	timestack += curtime - oldTime;
	oldTime = curtime;
	if (timestack >= 300)
	{
		timestack = 0;

		double size = rand() % 50 + 10.0;
		double posX = rand() % 1500 + 10.0;
		int speed = rand() % 10 + 5;
		Object* newObj = nullptr;

		switch (rand() % 2)
		{
		case 0:
			newObj = new Rect({ posX, 0 }, { size, size });
			break;
		case 1:
			newObj = new Circle({ posX, 0 }, size);
			break;
		default:
			break;
		}

		Projectile* newProjectile = new Projectile(speed);
		newProjectile->SetObj(newObj);
		projectiles.push_back(newProjectile);
	}

	list<Projectile*>::iterator iter = projectiles.begin();
	for (; iter != projectiles.end(); ++iter)
	{
		(*iter)->Update();
		if ((*iter)->GetObj()->Pos().y > 800)
		{
			(*iter)->Delete();
			iter = projectiles.erase(iter);
			if (iter == projectiles.end())
			{
				break;
			}
		}
	}
}

void ProjectileList::Render(HDC hdc)
{
	for (Projectile* item : projectiles)
	{
		item->GetObj()->Render(hdc);
	}
}
