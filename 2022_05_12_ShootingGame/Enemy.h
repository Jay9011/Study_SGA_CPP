#pragma once

struct PointFlag
{
	bool isUse;
	const Vector2 pos;
};

class Enemy : public GameObject
{
public:
	Enemy();
	virtual ~Enemy();

	virtual void Update() override;
	virtual void Render(HDC hdc) override;

	void Init();
	void Setting(ENEMY_TYPE type);
	void Setting(ENEMY_TYPE type, Texture* texture);
	void Setting(ENEMY_TYPE type, Texture* texture, PointFlag* spawn, PointFlag* arrive);

	ENEMY_TYPE GetType() { return type; }

private:
	void Move();
	void Destroy();

	// Enemy Setting
	ENEMY_TYPE	type;

	int			maxHp;
	int			curHp;

	double		velocity;
	Vector2		direction;

	PointFlag*	spawnPoint;
	PointFlag*	arrivalPoint;

	Rect*		collider;
	Texture*	bodyImg;
	Rect*		bodyImgRect;
	POINT		bodyFrame;

	double		frameTime;
	double		reloadTime;

	// Debug Object
	HPEN	oldpen;
	HBRUSH	oldbrush;
	HPEN	pen;
	HBRUSH	brush;
};

