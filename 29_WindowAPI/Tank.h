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
	Circle*   body;	// ��ü
	Line*	barrel;	// ����

	//CannonBall* cannonBall;
	CannonBallManager* cbManager;

	double angle;
	double speed;
	double barrelLength;

	double power;
	double deltaPower;

	bool isPush;

	// �Ŀ� ������
	Rect* powerBarFront;
	Rect* powerBarBack;

	// ���� �귯��
	HBRUSH     oldBrush;
	HBRUSH    grayBrush;
	HBRUSH magentaBrush;
};
