#pragma once
class EnemyManager
{
public:
	EnemyManager(UINT _count);
	~EnemyManager();

	void Update();
	void Render();

	void SpawnEnemy();

private:
	vector<Enemy*> enemies;

	double time;
	double randomTime;

};

