#pragma once
class AKBall
{
public:
	AKBall();
	~AKBall();

private:
	Circle* ball;
	double	speed;
	Vector2	direction;

	bool	isReady;
	bool	isFire;

	HPEN	oldPen;
	HBRUSH	oldBrush;

	HPEN	blackPen;
	HPEN	cyanPen;
	HPEN	bluePen;

	HBRUSH	blackBrush;
	HBRUSH	cyanBrush;
	HBRUSH	blueBrush;

public:
	void	Update();
	void	Render(HDC hdc);

	void	SetReady(Vector2 _pos);
	void	Fire(Vector2 dir);
	void	Fire(Vector2 pos, Vector2 dir);

	bool	IsReady()	{ return isReady; }
	bool	IsFire()	{ return isFire; }

	void	SetPos(Vector2 pos) { ball->Pos() = pos; };
	Vector2 Pos()		{ return ball->Pos(); }
	double	Radius()	{ return ball->Radius(); };
	
	double	Left()		{ return ball->Left(); }
	double	Right()		{ return ball->Right(); }
	double	Top()		{ return ball->Top(); }
	double	Bottom()	{ return ball->Bottom(); }
	
	void	ChangeDirection(bool _cXPos, bool _cYPos);
	void	DeleteBall()
	{
		isReady = false;
		isFire = false;
		direction = Vector2();
		ball->Pos() = { 0, 0 };
	}
};

