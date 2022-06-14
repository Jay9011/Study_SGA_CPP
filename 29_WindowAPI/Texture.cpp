#include "Framework.h"
#include "Texture.h"

Texture::Texture(wstring path, Gdiplus::Color transColor)
	: maxFrame({ 1, 1 })
{
	graphics = new Gdiplus::Graphics(backDC);
	image = Gdiplus::Image::FromFile(path.c_str());

	originSize.x = image->GetWidth();
	originSize.y = image->GetHeight();

	frameSize = originSize;

	attributes.SetColorKey(transColor, transColor);
}

Texture::Texture(wstring path, long frameX, long frameY, Gdiplus::Color transColor)
	: maxFrame({ frameX, frameY })
{
	graphics = new Gdiplus::Graphics(backDC);
	image = Gdiplus::Image::FromFile(path.c_str());

	originSize.x = image->GetWidth();
	originSize.y = image->GetHeight();

	frameSize.x = originSize.x / frameX;
	frameSize.y = originSize.y / frameY;

	attributes.SetColorKey(transColor, transColor);
}

Texture::~Texture()
{
	delete graphics;
	delete image;
}

void Texture::Render(Rect* rect)
{
	destRect.X		= rect->Left();
	destRect.Y		= rect->Top();
	destRect.Width	= rect->Size().x;
	destRect.Height	= rect->Size().y;

	graphics->DrawImage
	(
		image,
		destRect,
		0, 0,
		image->GetWidth(), image->GetHeight(),
		Gdiplus::Unit::UnitPixel,
		&attributes
	);
}

void Texture::Render(Rect* rect, POINT curFrame)
{
	destRect.X = rect->Left();
	destRect.Y = rect->Top();
	destRect.Width = rect->Size().x;
	destRect.Height = rect->Size().y;

	graphics->DrawImage
	(
		image,
		destRect,
		frameSize.x * curFrame.x,
		frameSize.y * curFrame.y,
		frameSize.x,
		frameSize.y,
		Gdiplus::Unit::UnitPixel,
		&attributes
	);
}

void Texture::Render(Rect* rect, RECT xmlFrame)
{
	destRect.X = rect->Left();
	destRect.Y = rect->Top();
	destRect.Width = rect->Size().x;
	destRect.Height = rect->Size().y;

	graphics->DrawImage
	(
		image,
		destRect,
		xmlFrame.left,
		xmlFrame.top,
		xmlFrame.right,
		xmlFrame.bottom,
		Gdiplus::Unit::UnitPixel,
		&attributes
	);
}

void Texture::AlphaRender(Rect* rect, UINT alpha)
{
}

void Texture::AlphaRender(Rect* rect, POINT curFrame, UINT alpha)
{
}
