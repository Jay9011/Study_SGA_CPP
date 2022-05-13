#pragma once

struct PointFlag
{
	bool	isUse;
	POINT	pos;
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

	ENEMY_TYPE GetType() { return type; }

private:
	// Enemy Setting
	ENEMY_TYPE	type;

	int			maxHp;
	int			curHp;

	double		velocity;
	PointFlag*	spawnPoint;
	PointFlag*	arrivalPoint;

	Rect*		collider;
	Texture*	bodyImg;
	Rect*		bodyImgRect;
	POINT		bodyFrame;

	int			frameTime;

	// Debug Object
	HPEN	oldpen;
	HBRUSH	oldbrush;
	HPEN	pen;
	HBRUSH	brush;
};

