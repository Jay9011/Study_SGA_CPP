#pragma once
class SGABrickManager
{
public:
	SGABrickManager();
	~SGABrickManager();

	void Render(HDC hdc);

	void CreateStage1();
	void CreateStage2();

	void ClearStage();
	bool GetRemainBricks();

	Direction CollisionDir(Circle* circle);

private:
	vector<SGABrick*>	bricks;

};
