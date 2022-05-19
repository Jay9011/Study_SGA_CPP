#pragma once

class Plane;

class EnemyManager
{
public:
	EnemyManager(UINT _count);
	~EnemyManager();

	void Update();
	void Render();

	void SpawnEnemy();

	void Collision(Plane* player);

	vector<Enemy*>& GetEnemies() { return enemies; }

private:
	vector<Enemy*> enemies;

	double time;
	double randomTime;

};

