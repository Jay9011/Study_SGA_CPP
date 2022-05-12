#pragma once
class SGAArkanoidScene : public Scene
{
public:
	SGAArkanoidScene();
	~SGAArkanoidScene();

	// Scene��(��) ���� ��ӵ�
	virtual void Update() override;
	virtual void Render(HDC hdc) override;

private:
	SGABar*			 player;
	SGABall*		 ball;
	//SGABrick*		 brick;
	SGABrickManager* bManager;
};