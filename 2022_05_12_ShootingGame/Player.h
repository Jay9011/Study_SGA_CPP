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

	Rect*	GetCollider()	{ return collider; }
	int		GetCurHp()		{ return curHp; }
	int		GetScore()		{ return score; }
	void	SetScore(int _score) { score += _score; }

private:
	// Player Setting
	int			maxHp;
	int			curHp;
	int			maxScore;
	int			score;
	bool		invincibility;
	int			inviTime;

	double		velocity;
	PLAYERSTATE	state;

	Rect*		collider;
	Texture*	bodyImg;
	Rect*		bodyImgRect;
	POINT		bodyFrame;
	bool		bodyHide;

	int			curReloadTime;
	int			maxReloadTime;
	int			frameTime;
	
	// GdiPlus
	Gdiplus::Graphics* graphics;

	// Debug Object
	HPEN	oldpen;
	HBRUSH	oldbrush;
	HPEN	pen;
	HBRUSH	brush;
};

