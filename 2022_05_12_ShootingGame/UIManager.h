#pragma once
#define bgCnt 4
#define cloudCnt 10

class UIManager
{
	SNG_CREATE(UIManager)
private:
	UIManager();
	~UIManager();

public:
	void Update();
	void Render(HDC hdc);

private:
	Texture*	bgImg;
	Rect*		bgImgRect[bgCnt];
	POINT		bgFrame;

	Texture*	cloudsImg;
	Rect*		cloudsImgRect[cloudCnt];
};

