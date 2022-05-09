#include "Framework.h"
#include "ImageScene.h"

ImageScene::ImageScene()
	: imageSize({448, 104})
	, frame({8, 2})
	, time(0)
	, curFrame(0)
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

	siva = (HBITMAP)LoadImage
	(
		hInst,
		L"Textures/siva_run.bmp",
		IMAGE_BITMAP,
		448, 104,
		LR_LOADFROMFILE
	);
}

ImageScene::~ImageScene()
{
	DeleteDC(memDC);
	DeleteObject(hBitmap);
	DeleteObject(siva);
}

void ImageScene::Update()
{
	time++;

	if (time > 10)
	{
		time = 0;
		++curFrame %= (frame.x - 2);
	}
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
		843, 843,
		memDC,
		0, 0,
		843, 843,
		SRCCOPY
	);

	SelectObject(memDC, siva);
	GdiTransparentBlt
	(
		hdc,
		WIN_CENTER_X, WIN_CENTER_Y,
		100, 100,
		memDC,
		imageSize.x / frame.x * (curFrame + 2), 0,		// LEFT TOP 좌표
		imageSize.x / frame.x, imageSize.y / frame.y,	// 이미지 사이즈
		COLOR_MAGENTA
	);

}

