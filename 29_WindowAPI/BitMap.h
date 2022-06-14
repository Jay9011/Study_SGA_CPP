#pragma once
class BitMap : public Texture
{
public:
	BitMap(wstring _file, long _width, long _height, COLORREF _transColor = COLOR_MAGENTA);
	BitMap(wstring _file, long _width, long _height, long _frameX, long _frameY, COLORREF _transColor = COLOR_MAGENTA);
	~BitMap();

	virtual void Render(Rect* rect) override;
	virtual void Render(Rect* rect, POINT curFrame) override;
	
	virtual void AlphaRender(Rect* rect, UINT alpha) override;
	virtual void AlphaRender(Rect* rect, POINT curFrame, UINT alpha) override;

	double GetLandY(double posX) override;
	HDC GetMemDC() override { return this->memDC; }

private:
	HDC     memDC;
	HBITMAP bitmap;

	COLORREF transColor;

	HDC     alphaDC;
	HBITMAP alphaBitmap;

	BLENDFUNCTION blendFunction;
};

