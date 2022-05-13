#pragma once
class PlayerBullet : public Bullet
{
public:
	PlayerBullet();
	virtual ~PlayerBullet();

	virtual void Update() override;
	virtual void Render(HDC hdc) override;
	virtual void Fire(Vector2 pos, Vector2 dir) override;
};

