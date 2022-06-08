#pragma once
class XMLScene : public Scene
{
public:
	XMLScene();
	~XMLScene() override;

	// Scene을(를) 통해 상속됨
	virtual void Update() override;
	virtual void Render(HDC hdc) override;

	void ClickEvent();

private:
	Knight* knight;
	Button* button;
};

