#pragma once
class Time
{
public:
	Time(LPDIRECT3DDEVICE9 device);
	~Time();

public:
	static double Delta() { return timeElapsed; }

	void Update();
	void Render();

	UINT GetFPS() { return frameRate; }

private:
	// 1�����Ӵ� ��� �ð�
	static double timeElapsed;

	INT64 curTick;
	INT64 lastTick;
	INT64 ticksPerSecond;

	UINT frameCount;
	UINT frameRate;

	double oneSecCount;
	double runningTime;

	double timeScale;

	// V-Sync
	double scanningRate; // �ֻ���

	// Text ���
	LPD3DXFONT font;
};

