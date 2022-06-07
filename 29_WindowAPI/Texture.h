#pragma once

class Texture
{
public:
	Texture(wstring path, Gdiplus::Color transColor = Gdiplus::Color::Magenta);
	Texture(wstring path, long frameX, long frameY, Gdiplus::Color transColor = Gdiplus::Color::Magenta);
	~Texture();

	void Render(Rect* rect);
	void Render(Rect* rect, POINT curFrame);
	void Render(Rect* rect, RECT xmlFrame);

	POINT	GetMaxFrame()  { return maxFrame; }
	Vector2 GetFrameSize() { return Vector2((double)frameSize.x, (double)frameSize.y); }

private:
	Gdiplus::Image*		image;
	Gdiplus::Graphics*	graphics;

	Gdiplus::Rect	destRect;
	
	POINT	 frameSize;
	POINT	originSize;

	POINT	  maxFrame;

	Gdiplus::ImageAttributes attributes;
};
