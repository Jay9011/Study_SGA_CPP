#pragma once

class EnemyManager
{
	SNG_CREATE(EnemyManager)
private:
	EnemyManager();
	~EnemyManager();

public:
	void Update();
	void Render(HDC hdc);

	void EnemySpawn();

	vector<Enemy*>	enemies;

private:
	void SetSpawnPoint();
	void SetArrivalPoint();
	bool EnemySetting(PointFlag* point);

	double	timer;
	double	maxTimer;
	double	deltaScoreTimer;

	int usableAPoint;
	Texture*		enemyImg[(int)ENEMY_TYPE::END];

	vector<PointFlag*>	spawnPoint;
	vector<PointFlag*>	arrivalPoint;
};

