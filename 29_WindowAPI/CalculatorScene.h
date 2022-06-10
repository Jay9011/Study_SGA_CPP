#pragma once

enum class NUMBER
{
	ZERO,
	ONE,
	TWO,
	THREE,
	FOUR,
	FIVE,
	SIX,
	SEVEN,
	EIGHT,
	NINE,
	END
};
enum class OPERATOR
{
	NONE,
	ADD,
	SUB,
	MUL,
	DIV,
	RESULT,
	CLEAR,
	END
};

class CalculatorScene : public Scene
{
public:
	CalculatorScene();
	~CalculatorScene();

private:
	map<string, Button*> padButtons;
	
	RECT*    numbers;
	Texture* numbersTexture;

	RECT*    opers;
	Texture* opersTexture;
	
	OPERATOR oper;
	OPERATOR tmpOper;
	int      beforeRst;
	int      rstNum;
	int      tmpNum;
	int      showingNum;

public:
	// Scene을(를) 통해 상속됨
	virtual void Update() override;
	virtual void Render(HDC hdc) override;

	void OperatorChange(OPERATOR _oper);
	void AccNumber(int _num);
	void SetShowingNum(int _num) { showingNum = _num; }

	void LoadXML();
	void ButtonSetting();
	void RenderNumber(UINT _digit, NUMBER _num);
	void RenderResultAndOperator();
};
