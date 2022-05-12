#pragma once

#define BRICK_WIDTH		100
#define BRICK_HEIGHT	 20
#define BRICKXCOUNT		 12
#define BRICKYCOUNT		 20

class AKBrick
{
public:
	AKBrick();
	~AKBrick();

private:
	Rect*	body;
	short	hp;

	HPEN	oldPen;
	HBRUSH	oldBrush;

	HPEN	grayPen;
	HBRUSH	redBrush;
	HBRUSH	orangeBrush;
	HBRUSH	yellowBrush;
	HBRUSH	greenBrush;

public:
	bool isUse;

public:
	void Update();
	void Render(HDC hdc);

	short	GetHp()				{ return hp; }
	void	SetHp(short _hp)	{ hp = _hp; }
	void	MinusHp(short _hp)	{ hp -= _hp; }
	void	ResetBrick();

	Rect* GetRect() { return body; }
	
};

