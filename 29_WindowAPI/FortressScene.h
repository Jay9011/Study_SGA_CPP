#pragma once
class FortressScene : public Scene
{
public:
	FortressScene();
	~FortressScene();

	// Scene을(를) 통해 상속됨
	virtual void Update() override;
	virtual void Render(HDC hdc) override;

private:
	Tank* tank;
};
