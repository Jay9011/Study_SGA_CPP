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
	void SetPlayer(Plane* player);

private:
	vector<Enemy*> enemies;

	double time;
	double randomTime;

};

