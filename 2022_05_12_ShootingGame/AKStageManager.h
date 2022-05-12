#pragma once
class AKStageManager
{
public:
	AKStageManager(AKUI* _ui);
	~AKStageManager();

private:
	AKUI* ui;
	int stage;
	vector<vector<vector<int>>> maps;

public:
	vector<AKBrick*> bricks;

public:
	void Update();
	void Render(HDC hdc);
	bool IsStageClear();
	bool NextStage();

private:
	void initStage();
	void StageChange();
};

