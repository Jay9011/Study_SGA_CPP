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

	double angle;
	double barrelLength;
};
