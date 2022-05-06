#include "Framework.h"
#include "ImageScene.h"

ImageScene::ImageScene()
{
	HDC hdc = GetDC(hWnd);
	memDC = CreateCompatibleDC(hdc);

	ReleaseDC(hWnd, hdc);

	hBitmap = (HBITMAP)LoadImage
	(
		hInst, 
		L"Textures/BTS.bmp", 
		IMAGE_BITMAP, 
		843, 843, 
		LR_LOADFROMFILE
	);
}

ImageScene::~ImageScene()
{
	DeleteDC(memDC);
	DeleteObject(hBitmap);
}

void ImageScene::Update()
{
}

void ImageScene::Render(HDC hdc)
{
	SelectObject(memDC, hBitmap);

	/*BitBlt
	(
		hdc,
		0, 0,
		WIN_WIDTH, WIN_HEIGHT,
		memDC,
		0, 0,
		SRCCOPY
	);*/

	StretchBlt
	(
		hdc,
		0, 0,
		WIN_WIDTH, WIN_HEIGHT,
		memDC,
		0, 0,
		843, 843,
		SRCCOPY
	);

	/*GdiTransparentBlt
	(
		hdc,
		WIN_CENTER_X, WIN_CENTER_Y,
		100, 100,

	);*/
}
