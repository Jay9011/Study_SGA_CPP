#pragma once
class Tank
{
public:
	Tank();
	~Tank();

	void Update();
	void Render(HDC hdc);

private:
	Circle*   body;	// ��ü
	Line*	barrel;	// ����

	CannonBall* cannonBall;

	double angle;
	double speed;
	double barrelLength;

	double power;
	double deltaPower;

	bool isPush;
};
