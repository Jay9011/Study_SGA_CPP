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
	Rect*		collider;
	Texture*	bodyImg;
	Rect*		bodyImgRect;
	POINT		bodyFrame;

	double		velocity;
	int			curReloadTime;
	int			maxReloadTime;
	int			frameTime;
	PLAYERSTATE	state;
	

	// Debug Object
	HPEN	oldpen;
	HBRUSH	oldbrush;
	HPEN	pen;
	HBRUSH	brush;
};

