#pragma once
class AKUI
{
public:
	AKUI();
	~AKUI();

private:
	int		border;
	Rect*	scoreBox;
	Rect*	stageBox;

	int		score;

	HPEN	oldPen;
	HBRUSH	oldBrush;

	HPEN	whitePen;
	HPEN	blackPen;
	HPEN	redPen;
	HBRUSH	whiteBrush;
	HBRUSH	blackBrush;

public:
	void Update();
	void Render(HDC hdc);

	void SetScore(int _addScore);

	double GetStageLeft() { return stageBox->Left(); }
	double GetStageTop() { return stageBox->Top(); }
	double GetStageRight() { return stageBox->Right(); }
	double GetStageBottom() { return stageBox->Bottom(); }
};

