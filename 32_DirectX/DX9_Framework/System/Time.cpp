#include "Framework.h"
#include "Time.h"

double Time::timeElapsed = 0;

Time::Time()
	:curTick(0), frameCount(0), frameRate(0), oneSecCount(0), runningTime(0), scanningRate(200)
{
	//�ʴ� CPU ����(tick) ��
	QueryPerformanceFrequency((LARGE_INTEGER*)&ticksPerSecond);	

	//������� CPU ����(tick) ���� ��
	QueryPerformanceCounter((LARGE_INTEGER*)&lastTick);

	timeScale = 1.0 / ticksPerSecond; // 1tick�� �ɸ��� �ð�

	//Text ���
	D3DXFONT_DESC desc = {};

	desc.Height  = 20;
	desc.Width   = 20;
	desc.CharSet = HANGUL_CHARSET;

	wstring str = L"����ü";
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
	//1�����ӵ��� �帥 �ð�(��)
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

	//������ tick ��� ����
	lastTick = curTick;

	frameCount++;

	//1�� üũ�� ���� ����
	oneSecCount += timeElapsed;
	
	//Frame Per Second�� ���ϴ� ����
	if (oneSecCount >= 1.0)
	{
		oneSecCount = 0;
	
		frameRate = frameCount;
		frameCount = 0;
	}

	//�����ð�
	runningTime += timeElapsed;
}

void Time::Render()
{
	wstring str = L"FPS : " + to_wstring(frameRate);

	RECT rect = { WIN_WIDTH - 200, 5, WIN_WIDTH, 40 };

	font->DrawText(nullptr, str.c_str(), -1, &rect, DT_LEFT, 0xFFFFFFFF);
}
