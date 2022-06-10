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
	 EffectManager::Create();
		  Keyboard::Create();
	          Time::Create();
	  SoundManager::Create();
	{}
	//scene = new PaintScene();
	//scene = new CollisionScene();
	//scene = new FortressScene();
	//scene = new ArkanoidScene();
	//scene = new SGAArkanoidScene();
	//scene = new ImageScene();
	//scene = new TextureScene();
	//scene = new AnimationScene();
	//scene = new XMLScene();
	scene = new EffectScene();

}

MainGame::~MainGame()
{
	delete scene;
	
	  SoundManager::Delete();
	          Time::Delete();
		  Keyboard::Delete();
	 EffectManager::Delete();
	TextureManager::Delete();

	Gdiplus::GdiplusShutdown(token);
}

void MainGame::Update()
{
	EffectManager::Get()->Update();
	         Time::Get()->Update();
	 SoundManager::Get()->Update();

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
	EffectManager::Get()->Render();
	         Time::Get()->Render();

	BitBlt(	   hdc, 0, 0, WIN_WIDTH, WIN_HEIGHT, 
			backDC, 0, 0, 
			SRCCOPY			// 도화지를 무엇으로 칠할 것인가
		  );
}
