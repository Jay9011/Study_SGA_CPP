#include "Framework.h"
#include "Time.h"

double Time::timeElapsed = 0;

Time::Time(LPDIRECT3DDEVICE9 device)
	: curTick(0)
	, lastTick(0)
	, ticksPerSecond(0)
	, frameCount(0)
	, frameRate(0)
	, oneSecCount(0)
	, runningTime(0)
	, timeScale(1)
	, scanningRate(200)
{
	// 초당 CPU 진동(tick) 수
	QueryPerformanceFrequency((LARGE_INTEGER*)&ticksPerSecond);

	// 현재까지 CPU 진동(tick) 누적 수
	QueryPerformanceCounter((LARGE_INTEGER*)&lastTick);

	// Text 출력
	D3DXFONT_DESC desc = {};

	desc.Height   = 20;
	desc.Width    = 20;
	desc.CharSet  = HANGUL_CHARSET;

	wstring str = L"바탕체";
	wcscpy_s(desc.FaceName, str.c_str());

	D3DXCreateFontIndirect(device, &desc, &font);
}

Time::~Time()
{
	font->Release();
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
	wstring str = L"FPS : " + to_wstring(frameRate);

	RECT rect = { WIN_WIDTH - 200, 5, WIN_WIDTH, 40 };

	font->DrawText(nullptr, str.c_str(), -1, &rect, DT_LEFT, 0xFFFFFFFF);
}
