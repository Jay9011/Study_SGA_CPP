#pragma once

class CalculatorScene : public Scene
{
public:
	CalculatorScene();
	~CalculatorScene();

public:
	// Scene��(��) ���� ��ӵ�
	virtual void Update() override;
	virtual void Render(HDC hdc) override;

	map<string, Button*> padButtons;
};
