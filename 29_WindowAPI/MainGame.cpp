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
	          Time::Create();
	{}
	//scene = new PaintScene();
	//scene = new CollisionScene();
	//scene = new FortressScene();
	//scene = new ArkanoidScene();
	//scene = new SGAArkanoidScene();
	//scene = new ImageScene();
	//scene = new TextureScene();
	scene = new AnimationScene();

}

MainGame::~MainGame()
{
	delete scene;
	
	          Time::Delete();
		  Keyboard::Delete();
	TextureManager::Delete();

	Gdiplus::GdiplusShutdown(token);
}

void MainGame::Update()
{
	Time::Get()->Update();

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
	Time::Get()->Render();

	BitBlt(	   hdc, 0, 0, WIN_WIDTH, WIN_HEIGHT, 
			backDC, 0, 0, 
			SRCCOPY			// 도화지를 무엇으로 칠할 것인가
		  );
}
