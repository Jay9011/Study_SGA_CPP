#pragma once

class CalculatorScene : public Scene
{
public:
	CalculatorScene();
	~CalculatorScene();

public:
	// Scene을(를) 통해 상속됨
	virtual void Update() override;
	virtual void Render(HDC hdc) override;

	map<string, Button*> padButtons;
};
