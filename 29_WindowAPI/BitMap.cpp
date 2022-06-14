#include "Framework.h"
#include "BitMap.h"

BitMap::BitMap(wstring _file, long _width, long _height, COLORREF _transColor)
	: transColor(_transColor)
{
	HDC hdc = GetDC(hWnd);
	memDC   = CreateCompatibleDC(hdc);
	alphaDC     = CreateCompatibleDC(hdc);
	alphaBitmap = CreateCompatibleBitmap(hdc, _width, _height);
	ReleaseDC(hWnd, hdc);

	bitmap = (HBITMAP)LoadImage
	(
		hInst,
		_file.c_str(),
		IMAGE_BITMAP,
		_width, _height,
		LR_LOADFROMFILE
	);

	SelectObject(memDC  , bitmap);
	SelectObject(alphaDC, alphaBitmap);

	originSize = { _width, _height };
	frameSize  = { _width, _height };
	maxFrame   = { 1, 1 };
}

BitMap::BitMap(wstring _file, long _width, long _height, long _frameX, long _frameY, COLORREF _transColor)
	: transColor(_transColor)
{
	HDC hdc = GetDC(hWnd);
	memDC   = CreateCompatibleDC(hdc);
	alphaDC     = CreateCompatibleDC(hdc);
	alphaBitmap = CreateCompatibleBitmap(hdc, _width, _height);
	ReleaseDC(hWnd, hdc);

	bitmap = (HBITMAP)LoadImage
	(
		hInst,
		_file.c_str(),
		IMAGE_BITMAP,
		_width, _height,
		LR_LOADFROMFILE
	);

	SelectObject(memDC  , bitmap);
	SelectObject(alphaDC, alphaBitmap);

	originSize = { _width          , _height           };
	frameSize  = { _width / _frameX, _height / _frameY };
	maxFrame   = { _frameX         , _frameY           };
}

BitMap::~BitMap()
{
	DeleteObject(memDC);
	DeleteObject(bitmap);
}

void BitMap::Render(Rect* rect)
{
	GdiTransparentBlt
	(
		backDC,
		rect->Left(),
		rect->Top(),
		rect->Size().x,
		rect->Size().y,
		memDC,
		0, 0,
		frameSize.x, frameSize.y,
		transColor
	);
}

void BitMap::Render(Rect* rect, POINT curFrame)
{
	GdiTransparentBlt
	(
		backDC,
		rect->Left(),
		rect->Top(),
		rect->Size().x,
		rect->Size().y,
		memDC,
		frameSize.x * curFrame.x, frameSize.y * curFrame.y,
		frameSize.x, frameSize.y,
		transColor
	);
}

void BitMap::AlphaRender(Rect* rect, UINT alpha)
{
	blendFunction.SourceConstantAlpha = (BYTE)alpha;

	BitBlt
	(
		alphaDC,
		0, 0,
		frameSize.x, frameSize.y,
		backDC,
		0, 0,
		SRCCOPY
	);

	GdiTransparentBlt
	(
		alphaDC,
		0, 0,
		frameSize.x, frameSize.y,
		memDC,
		0, 0,
		frameSize.x, frameSize.y,
		transColor
	);

	GdiAlphaBlend
	(
		backDC,
		rect->Left(),
		rect->Top(),
		rect->Size().x,
		rect->Size().y,
		alphaDC,
		0, 0,
		frameSize.x, frameSize.y,
		blendFunction
	);
}

void BitMap::AlphaRender(Rect* rect, POINT curFrame, UINT alpha)
{
}

double BitMap::GetLandY(double posX)
{
	for (UINT i = 0; i < frameSize.y; ++i)
	{
		COLORREF color = GetPixel(memDC, posX, i);

		if (color != transColor)
			return i;
	}

	return frameSize.y;
}
