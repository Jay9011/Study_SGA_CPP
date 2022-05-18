#include "Framework.h"
#include "MainGame.h"

MainGame::MainGame()
{
	srand(time(NULL));

	HDC hdc = GetDC(hWnd);
	backDC  = CreateCompatibleDC(hdc);
	hBitmap = CreateCompatibleBitmap(hdc, WIN_WIDTH, WIN_HEIGHT);

	SelectObject(backDC, hBitmap);

	ReleaseDC(hWnd, hdc);

	Gdiplus::GdiplusStartup(&token, &input, nullptr);

	TextureManager::Create();
		  Keyboard::Create();

	//scene = new PaintScene();
	//scene = new CollisionScene();
	//scene = new FortressScene();
	//scene = new ArkanoidScene();
	//scene = new SGAArkanoidScene();
	//scene = new ImageScene();
	scene = new TextureScene();
}

MainGame::~MainGame()
{
	delete scene;

		  Keyboard::Delete();
	TextureManager::Delete();

	Gdiplus::GdiplusShutdown(token);
}

void MainGame::Update()
{
	scene->Update();
}

void MainGame::Render(HDC hdc)
{
	PatBlt( backDC, 0, 0, WIN_WIDTH, WIN_HEIGHT,
			WHITENESS		// 도화지를 무엇으로 초기화 시킬 것인가
			//BLACKNESS
			//SRCCOPY
		  );

	scene->Render(backDC);

	BitBlt(	   hdc, 0, 0, WIN_WIDTH, WIN_HEIGHT, 
			backDC, 0, 0, 
			SRCCOPY			// 도화지를 무엇으로 칠할 것인가
		  );
}
