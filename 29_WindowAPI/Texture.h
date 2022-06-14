#pragma once

class Texture
{
public:
	Texture() = default;
	Texture(wstring path, Gdiplus::Color transColor = Gdiplus::Color::Magenta);
	Texture(wstring path, long frameX, long frameY, Gdiplus::Color transColor = Gdiplus::Color::Magenta);
	~Texture();

	virtual void Render(Rect* rect);
	virtual void Render(Rect* rect, POINT curFrame);
	virtual void Render(Rect* rect, RECT xmlFrame);

	virtual void AlphaRender(Rect* rect, UINT alpha);
	virtual void AlphaRender(Rect* rect, POINT curFrame, UINT alpha);

	POINT	GetMaxFrame()  { return maxFrame; }
	Vector2 GetFrameSize() { return Vector2((double)frameSize.x, (double)frameSize.y); }

	virtual double GetLandY(double posX) { return 0.0; }

	virtual HDC GetMemDC() { return nullptr; }

protected:
	POINT	 frameSize;
	POINT	originSize;

	POINT	  maxFrame;

private:
	Gdiplus::Image*		image;
	Gdiplus::Graphics*	graphics;

	Gdiplus::Rect	destRect;
	
	Gdiplus::ImageAttributes attributes;
};
