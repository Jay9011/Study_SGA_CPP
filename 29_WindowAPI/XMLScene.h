#pragma once
class XMLScene : public Scene
{
public:
	XMLScene();
	~XMLScene() override;

	// Scene��(��) ���� ��ӵ�
	virtual void Update() override;
	virtual void Render(HDC hdc) override;

private:
	Knight* knight;
};

