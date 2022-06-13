#include "Framework.h"
#include "Time.h"

Time* Time::instance = nullptr;
double Time::timeElapsed = 0;

Time::Time()
	: curTick(0)
	, lastTick(0)
	, ticksPerSecond(0)
	, frameCount(0)
	, frameRate(0)
	, oneSecCount(0)
	, runningTime(0)
	, timeScale(1)
	, scanningRate(60)
{
	// �ʴ� CPU ����(tick) ��
	QueryPerformanceFrequency((LARGE_INTEGER*)&ticksPerSecond);

	// ������� CPU ����(tick) ���� ��
	QueryPerformanceCounter((LARGE_INTEGER*)&lastTick);
}

Time::~Time()
{
}

void Time::Create()
{
	if (instance == nullptr)
	{
		instance = new Time;
	}
}

void Time::Delete()
{
	if (instance != nullptr)
	{
		delete instance;
	}
}

Time* Time::Get()
{
	return instance;
}

void Time::Update()
{
	QueryPerformanceCounter((LARGE_INTEGER*)&curTick);
	// 1�����ӵ��� �帥 �ð�(��)
	// ticksPerSecond = tick / sec
	timeElapsed = (curTick - lastTick) / (double)ticksPerSecond;

	if (scanningRate != 0)
	{
		// �� �����Ӵ� �ִ� �ð��� �ֻ����� �����ش�. ( 1�����Ӵ� �帣�� �ð��� �����Ѵ�. )
		while (timeElapsed < (1.0 / scanningRate))
		{
			QueryPerformanceCounter((LARGE_INTEGER*)&curTick);
			timeElapsed = (curTick - lastTick) / (double)ticksPerSecond;
		}
	}

	// ������ tick ��� ����
	lastTick = curTick;

	++frameCount;

	// 1�� üũ�� ���� ����
	oneSecCount += timeElapsed;

	// Frame Per Second �� ���ϴ� ����
	if (oneSecCount >= 1.0)
	{
		oneSecCount = 0;
		frameRate = frameCount;
		frameCount = 0;
	}

	// �����ð�
	runningTime += timeElapsed;
}

void Time::Render()
{
	wstring str;
	
	str = L"FPS : " + to_wstring(frameRate);
	TextOut(backDC, 0, 0, str.c_str(), str.size());

	str = L"runningTime : " + to_wstring(runningTime);
	TextOut(backDC, 0, 20, str.c_str(), str.size());
}
