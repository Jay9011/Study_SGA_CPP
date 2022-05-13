#pragma once
class EnemyBullet : public Bullet
{
public:
	EnemyBullet(Texture* _bulletImg, Texture* _destroyImg);
	virtual ~EnemyBullet();

	virtual void Update() override;
	virtual void Render(HDC hdc) override;
	virtual void Fire(Vector2 pos, Vector2 dir) override;
};

