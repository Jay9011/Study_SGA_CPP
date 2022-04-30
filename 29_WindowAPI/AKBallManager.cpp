#include "Framework.h"
#include "AKBallManager.h"

AKBallManager::AKBallManager(UINT poolCount)
{
	for (UINT i = 0; i < poolCount; i++)
	{
		AKBall* akBall = new AKBall();
		arkanoidBalls.push_back(akBall);
	}
}

AKBallManager::~AKBallManager()
{
	for (AKBall* ball : arkanoidBalls)
		delete ball;

	arkanoidBalls.clear();
}

void AKBallManager::Update()
{
	for (AKBall* ball : arkanoidBalls)
	{
		ball->Update();
	}
}

void AKBallManager::Render(HDC hdc)
{
	for (AKBall* ball : arkanoidBalls)
	{
		ball->Render(hdc);
	}
}

bool AKBallManager::ResetBall()
{
	for (AKBall* ball : arkanoidBalls)
	{
		ball->DeleteBall();
	}

	return false;
}

bool AKBallManager::GetReady()
{
	for (AKBall* ball : arkanoidBalls)
	{
		if (ball->IsReady())
		{
			return true;
		}
	}
	return false;
}

AKBall* AKBallManager::SetReady(Vector2 pos)
{
	for (AKBall* ball : arkanoidBalls)
	{
		if (!ball->IsReady() && !ball->IsFire())
		{
			ball->SetReady(pos);
			return ball;
		}
	}
}

void AKBallManager::Fire(Vector2 dir)
{
	for (AKBall* ball : arkanoidBalls)
	{
		if (ball->IsReady() && !ball->IsFire())
		{
			ball->Fire(dir);
			return;
		}
	}
}

void AKBallManager::Fire(Vector2 pos, Vector2 dir)
{
	for (AKBall* ball : arkanoidBalls)
	{
		if (ball->IsReady() && !ball->IsFire())
		{
			ball->Fire(pos, dir);
			return;
		}
	}
}