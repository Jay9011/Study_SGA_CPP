#pragma once
class AKPlayer
{
public:
	AKPlayer(AKUI& _akui);
	~AKPlayer();

private:
	AKUI*	 arkanoidUI;
			 
	Rect*	 body;
	double	 speed;

	HBRUSH	 oldBrush;
	HPEN	 oldPen;
			 
	HBRUSH	 bodyColor;
	HPEN	 borderColor;

public:
	void Update();
	void Render(HDC hdc);

	Vector2 GetCore() { return Vector2((body->Left() + body->Right()) / 2.0, body->Bottom()); }
};

