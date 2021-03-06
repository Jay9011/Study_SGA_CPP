#pragma once

class Texture
{
public:
	Texture(wstring path, Gdiplus::Color transColor = Gdiplus::Color::Magenta);
	Texture(wstring path, long frameX, long frameY, Gdiplus::Color transColor = Gdiplus::Color::Magenta);
	~Texture();

	void Render(Rect* rect);
	void Render(Rect* rect, POINT curFrame);

	POINT GetMaxFrame() { return maxFrame; }

private:
	Gdiplus::Image*		image;
	Gdiplus::Graphics*	graphics;

	Gdiplus::Rect	destRect;
	
	POINT	 frameSize;
	POINT	originSize;

	POINT	  maxFrame;

	Gdiplus::ImageAttributes attributes;
};
