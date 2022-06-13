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
	// 초당 CPU 진동(tick) 수
	QueryPerformanceFrequency((LARGE_INTEGER*)&ticksPerSecond);

	// 현재까지 CPU 진동(tick) 누적 수
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
	// 1프레임동안 흐른 시간(초)
	// ticksPerSecond = tick / sec
	timeElapsed = (curTick - lastTick) / (double)ticksPerSecond;

	if (scanningRate != 0)
	{
		// 각 프레임당 최대 시간을 주사율과 맞춰준다. ( 1프레임당 흐르는 시간을 조율한다. )
		while (timeElapsed < (1.0 / scanningRate))
		{
			QueryPerformanceCounter((LARGE_INTEGER*)&curTick);
			timeElapsed = (curTick - lastTick) / (double)ticksPerSecond;
		}
	}

	// 마지막 tick 기록 갱신
	lastTick = curTick;

	++frameCount;

	// 1초 체크를 위한 변수
	oneSecCount += timeElapsed;

	// Frame Per Second 를 구하는 과정
	if (oneSecCount >= 1.0)
	{
		oneSecCount = 0;
		frameRate = frameCount;
		frameCount = 0;
	}

	// 누적시간
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
