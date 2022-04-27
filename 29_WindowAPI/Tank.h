#pragma once

#define MAX_POWER	650

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

	//CannonBall* cannonBall;
	CannonBallManager* cbManager;

	double angle;
	double speed;
	double barrelLength;

	double power;
	double deltaPower;

	bool isPush;

	// 파워 게이지
	Rect* powerBarFront;
	Rect* powerBarBack;

	// 색상 브러쉬
	HBRUSH     oldBrush;
	HBRUSH    grayBrush;
	HBRUSH magentaBrush;
};
