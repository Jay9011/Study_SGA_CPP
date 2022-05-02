#pragma once
class SGABar
{
public:
	SGABar();
	~SGABar();

	void Update();
	void Render(HDC hdc);

	void Move();

private:
	Rect*	rect;
	double	speed;

	HBRUSH	grayBrush;

};

