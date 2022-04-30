#pragma once
class AKPlayer
{
public:
	AKPlayer(AKUI& _akui, AKBallManager& _akbm);
	~AKPlayer();

private:
	AKUI*			arkanoidUI;
	AKBallManager*	arkanoidBallManager;
			 
	Rect*	 body;
	double	 speed;
	AKBall*	 readyBall;

	HBRUSH	 oldBrush;
	HPEN	 oldPen;
			 
	HBRUSH	 bodyColor;
	HPEN	 borderColor;

public:
	void Update();
	void Render(HDC hdc);

	Vector2 GetCore()		{ return Vector2((body->Left() + body->Right()) / 2.0, body->Bottom()); }
	Vector2 GetTopCenter()	{ return Vector2((body->Left() + body->Right()) / 2.0, body->Top()); }

	Vector2 GetPos()	{ return body->Pos(); }
	Vector2 GetSize()	{ return body->Size(); }
};

