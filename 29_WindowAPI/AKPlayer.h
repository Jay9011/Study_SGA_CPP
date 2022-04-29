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

};

