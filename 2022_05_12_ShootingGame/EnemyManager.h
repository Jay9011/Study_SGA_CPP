#pragma once

class EnemyManager
{
	SNG_CREATE(EnemyManager)
public:
	EnemyManager();
	~EnemyManager();

	void Update();
	void Render(HDC hdc);

	void EnemySpawn();

private:
	void SetSpawnPoint();
	void SetArrivalPoint();

	int	timer;

	vector<Enemy*>	enemies;
	Texture*		enemyImg[(int)ENEMY_TYPE::END];

	vector<PointFlag>	spawnPoint;
	vector<PointFlag>	arrivalPoint;
};

