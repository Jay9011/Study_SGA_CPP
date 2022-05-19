#pragma once
class BulletManager
{
public:
	BulletManager();
	~BulletManager();

	void Update();
	void Render();

	void Fire(Vector2 _pos, Vector2 _dir, double _speed);

	vector<Bullet*>& GetBullets() { return bullets; }

private:
	vector<Bullet*> bullets;

};

