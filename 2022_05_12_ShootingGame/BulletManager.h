#pragma once
class BulletManager
{
	SNG_CREATE(BulletManager)
private:
	BulletManager();
	~BulletManager();

public:
	void Update();
	void Render(HDC hdc);

	void PlayerFire(Vector2 pos, Vector2 dir);
	void EnemyFire (Vector2 pos, Vector2 dir);

private:
	vector<Bullet*> playerBullet;
	vector<Bullet*> enemyBullet;
};

