#include "Framework.h"
#include "MainGame.h"

MainGame::MainGame()
{
	HDC hdc = GetDC(hWnd);
	backDC  = CreateCompatibleDC(hdc);
	hBitmap = CreateCompatibleBitmap(hdc, WIN_WIDTH, WIN_HEIGHT);

	SelectObject(backDC, hBitmap);
	
	ReleaseDC(hWnd, hdc);
	srand((unsigned int)time(NULL));

	Keyboard::Create();
	Time::Create();

	scene = new ShootingScene();
}

MainGame::~MainGame()
{
	delete scene;

	Time::Delete();
	Keyboard::Delete();
}

void MainGame::Update()
{
	Time::Get()->Update();
	scene->Update();
}

void MainGame::Render(HDC hdc)
{
	PatBlt( backDC, 0, 0, WIN_WIDTH, WIN_HEIGHT,
			WHITENESS		// ��ȭ���� �������� �ʱ�ȭ ��ų ���ΰ�
			//BLACKNESS
			//SRCCOPY
		  );

	scene->Render(backDC);
	Time::Get()->Render();

	BitBlt(	   hdc, 0, 0, WIN_WIDTH, WIN_HEIGHT, 
			backDC, 0, 0, 
			SRCCOPY			// ��ȭ���� �������� ĥ�� ���ΰ�
		  );
}
