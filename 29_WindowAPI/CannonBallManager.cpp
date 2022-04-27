#include "Framework.h"
#include "CannonBallManager.h"

CannonBallManager::CannonBallManager(UINT poolCount)
{
	for (UINT i = 0; i < poolCount; i++)
	{
		// poolCount��ŭ �̸� �����Ҵ��� �Ѵ�.
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
	// ��� CannonBall�� Update()�� �����Ų��.
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
		// �߻簡 �� �� ��ü�� �߻��Ų��.
		if (!c->IsFire())
		{
			c->Fire(pos, angle, power);
			return;	// �߻簡 �� �� �ϳ��� ��ü�� �߻���״ٸ� �����Ų��.
		}
	}
}
