#include "Framework.h"
#include "Time.h"

double Time::timeElapsed = 0;

Time::Time()
	:curTick(0), frameCount(0), frameRate(0), oneSecCount(0), runningTime(0), scanningRate(200)
{
	//초당 CPU 진동(tick) 수
	QueryPerformanceFrequency((LARGE_INTEGER*)&ticksPerSecond);	

	//현재까지 CPU 진동(tick) 누적 수
	QueryPerformanceCounter((LARGE_INTEGER*)&lastTick);

	timeScale = 1.0 / ticksPerSecond; // 1tick에 걸리는 시간

	//Text 출력
	D3DXFONT_DESC desc = {};

	desc.Height  = 20;
	desc.Width   = 20;
	desc.CharSet = HANGUL_CHARSET;

	wstring str = L"바탕체";
	wcscpy_s(desc.FaceName, str.c_str());

	D3DXCreateFontIndirect(DEVICE, &desc, &font);
}

Time::~Time()
{
	font->Release();
}

void Time::Update()
{
	QueryPerformanceCounter((LARGE_INTEGER*)&curTick);
	//1프레임동안 흐른 시간(초)
	//ticksPerSecond = tick / sec = 100 / 1
	timeElapsed = (curTick - lastTick) * timeScale;

	if (scanningRate != 0)
	{
		while (timeElapsed < (1.0 / scanningRate))
		{
			QueryPerformanceCounter((LARGE_INTEGER*)&curTick);
			timeElapsed = (curTick - lastTick) * timeScale;
		}
	}

	//마지막 tick 기록 갱신
	lastTick = curTick;

	frameCount++;

	//1초 체크를 위한 변수
	oneSecCount += timeElapsed;
	
	//Frame Per Second를 구하는 과정
	if (oneSecCount >= 1.0)
	{
		oneSecCount = 0;
	
		frameRate = frameCount;
		frameCount = 0;
	}

	//누적시간
	runningTime += timeElapsed;
}

void Time::Render()
{
	wstring str = L"FPS : " + to_wstring(frameRate);

	RECT rect = { WIN_WIDTH - 200, 5, WIN_WIDTH, 40 };

	font->DrawText(nullptr, str.c_str(), -1, &rect, DT_LEFT, 0xFFFFFFFF);
}
