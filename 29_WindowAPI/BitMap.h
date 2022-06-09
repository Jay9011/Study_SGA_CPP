#pragma once
class BitMap : public Texture
{
public:
	BitMap(wstring _file, long _width, long _height, COLORREF _transColor = COLOR_MAGENTA);
	BitMap(wstring _file, long _width, long _height, long _frameX, long _frameY, COLORREF _transColor = COLOR_MAGENTA);
	~BitMap();

	void Render(Rect* rect) override;
	void Render(Rect* rect, POINT curFrame) override;

	double GetLandY(double posX) override;

private:
	HDC     memDC;
	HBITMAP bitmap;

	COLORREF transColor;
};

