#include "Framework.h"
#include "CannonBallManager.h"

CannonBallManager::CannonBallManager(UINT poolCount)
{
	for (UINT i = 0; i < poolCount; i++)
	{
		// poolCount만큼 미리 동적할당을 한다.
		CannonBall* cannonBall = new CannonBall;
		cannonBalls.push_back(cannonBall);
	}
}

CannonBallManager::~CannonBallManager()
{
	for (CannonBall* c : cannonBalls)
		delete c;
	
	cannonBalls.clear();
}

void CannonBallManager::Update()
{
	// 모든 CannonBall에 Update()를 실행시킨다.
	for (CannonBall* c : cannonBalls)
	{
		c->Update();
	}
}

void CannonBallManager::Render(HDC hdc)
{
	for (CannonBall* c : cannonBalls)
	{
		c->Render(hdc);
	}
}

void CannonBallManager::Fire(Point pos, double angle, double power)
{
	for (CannonBall* c : cannonBalls)
	{
		// 발사가 안 된 객체를 발사시킨다.
		if (!c->IsFire())
		{
			c->Fire(pos, angle, power);
			return;	// 발사가 안 된 하나의 객체를 발사시켰다면 종료시킨다.
		}
	}
}
