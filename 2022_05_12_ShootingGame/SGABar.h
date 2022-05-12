#pragma once
class SGABar
{
public:
	SGABar();
	~SGABar();

	void Update();
	void Render(HDC hdc);

	void Move();

	Rect* GetRect() { return rect; }

private:
	Rect*	rect;
	double	speed;

	HBRUSH	grayBrush;

};

