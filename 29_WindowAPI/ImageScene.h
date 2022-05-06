#pragma once
class ImageScene : public Scene
{
public:
	ImageScene();
	~ImageScene();

	virtual void Update() override;
	virtual void Render(HDC hdc) override;

private:
	HDC memDC;
	HBITMAP hBitmap;

};
