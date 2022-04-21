#pragma once
class Tank
{
public:
	Tank();
	~Tank();

	void Update();
	void Render(HDC hdc);

private:
	Circle*   body;	// 차체
	Line*	barrel;	// 포신

	double angle;
	double barrelLength;
};
