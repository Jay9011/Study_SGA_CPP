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

	  SceneManager::Create();
	TextureManager::Create();
	 EffectManager::Create();
		  Keyboard::Create();
	          Time::Create();
	  SoundManager::Create();
	   DataManager::Create();
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
	//scene = new EffectScene();
	//scene = new CalculatorScene();

	SceneManager::Get()->Add("XMLScene"   , new XMLScene);
	SceneManager::Get()->Add("EffectScene", new EffectScene);
	SceneManager::Get()->Add("CameraScene", new CameraScene);

	SceneManager::Get()->ChangeScene("CameraScene");
}

MainGame::~MainGame()
{
	//delete scene;
	   DataManager::Delete();
	  SoundManager::Delete();
	          Time::Delete();
		  Keyboard::Delete();
	 EffectManager::Delete();
	TextureManager::Delete();
	  SceneManager::Delete();

	Gdiplus::GdiplusShutdown(token);
}

void MainGame::Update()
{
	EffectManager::Get()->Update();
	 SoundManager::Get()->Update();
	//scene->Update();
	 SceneManager::Get()->Update();
	         Time::Get()->Update();
}

void MainGame::Render(HDC hdc)
{
	PatBlt( backDC, 0, 0, WIN_WIDTH, WIN_HEIGHT,
			WHITENESS		// 도화지를 무엇으로 초기화 시킬 것인가
			//BLACKNESS
			//SRCCOPY
		  );

	//scene->Render(backDC);
	 SceneManager::Get()->Render(backDC);

	EffectManager::Get()->Render();
	         Time::Get()->Render();

	BitBlt(	   hdc, 0, 0, WIN_WIDTH, WIN_HEIGHT, 
			backDC, 0, 0, 
			SRCCOPY			// 도화지를 무엇으로 칠할 것인가
		  );
}
