#pragma once
class FortressScene : public Scene
{
public:
	FortressScene();
	~FortressScene();

	// Scene��(��) ���� ��ӵ�
	virtual void Update() override;
	virtual void Render(HDC hdc) override;

private:
	Tank* tank;
};
