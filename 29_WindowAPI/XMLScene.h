#pragma once
class XMLScene : public Scene
{
public:
	XMLScene();
	~XMLScene() override;

	// Scene��(��) ���� ��ӵ�
	virtual void Update() override;
	virtual void Render(HDC hdc) override;

	virtual void Initialize() override;
	virtual void Release() override;

	void ClickEvent();

private:
	//Knight* knight;
	Button* button;

	Texture* texture;
	Rect*    rect;

	Texture* siva;
	Rect*    sivaRect;
	POINT    curFrame;

	int  alpha;
	bool isIncrease;
};

