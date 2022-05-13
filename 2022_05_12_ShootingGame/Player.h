#pragma once
#include "GameObject.h"

enum class PLAYERSTATE
{
	MOVE_LEFT,
	MOVE_RIGHT,
	NONE,
};

class Player : public GameObject
{
public:
	Player();
	virtual ~Player();

	virtual void Update() override;
	virtual void Render(HDC hdc) override;

private:
	// Player Setting
	int			maxHp;
	int			curHp;
	int			maxScore;
	int			score;
	bool		invincibility;

	double		velocity;
	PLAYERSTATE	state;

	Rect*		collider;
	Texture*	bodyImg;
	Rect*		bodyImgRect;
	POINT		bodyFrame;

	int			curReloadTime;
	int			maxReloadTime;
	int			frameTime;
	

	// Debug Object
	HPEN	oldpen;
	HBRUSH	oldbrush;
	HPEN	pen;
	HBRUSH	brush;
};

