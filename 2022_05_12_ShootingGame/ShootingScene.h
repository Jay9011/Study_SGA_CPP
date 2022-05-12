#pragma once
class ShootingScene : public Scene
{
public:
	ShootingScene();
	~ShootingScene();

	virtual void Update() override;
	virtual void Render(HDC hdc) override;

private:
	// Gdiplus Setting
	Gdiplus::GdiplusStartupInput input;
	ULONG_PTR	token;

	int			time;
};

