#include "Framework.h"
#include "ArkanoidScene.h"

ArkanoidScene::ArkanoidScene()
	: gameover(false)
{
	arkanoidUI = new AKUI();
	arkanoidBallManager = new AKBallManager(10);
	arkanoidStageManager = new AKStageManager(arkanoidUI);
	arkanoidPlayer = new AKPlayer(arkanoidUI, arkanoidBallManager);
	arkanoidCollisionManager = new AKCollisionManager
	(
		arkanoidUI,
		arkanoidPlayer,
		arkanoidBallManager,
		arkanoidStageManager
	);
}

ArkanoidScene::~ArkanoidScene()
{
	delete arkanoidCollisionManager;
	delete arkanoidPlayer;
	delete arkanoidStageManager;
	delete arkanoidBallManager;
	delete arkanoidUI;
}

void ArkanoidScene::Update()
{
	if (!gameover)
	{
		arkanoidUI->Update();
		arkanoidBallManager->Update();
		arkanoidStageManager->Update();
		arkanoidPlayer->Update();
		arkanoidCollisionManager->Update();

		life = arkanoidPlayer->GetLife();
		if (life <= 0)
		{
			gameover = true;
		}

		if (arkanoidStageManager->IsStageClear())
		{
			arkanoidBallManager->ResetBall();
			if (!arkanoidStageManager->NextStage())
			{
				gameover = true;
			}
		}
	}
}

void ArkanoidScene::Render(HDC hdc)
{
	arkanoidUI->Render(hdc);
	arkanoidBallManager->Render(hdc);
	arkanoidPlayer->Render(hdc);
	arkanoidStageManager->Render(hdc);
	arkanoidCollisionManager->Render(hdc);

	wstring str = L"남은 생명 : ";
	str += to_wstring(life);
	TextOut(hdc
		, arkanoidUI->GetScoreRight() - 100
		, (arkanoidUI->GetScoreBottom() - arkanoidUI->GetScoreTop()) / 2
		, str.c_str()
		, str.length()
	);

	if (gameover)
	{
		wstring str = L"Game Over !!!";
		TextOut(hdc
			, (WIN_WIDTH / 2) - str.length()
			, WIN_HEIGHT / 2
			, str.c_str()
			, str.length()
		);
	}
}