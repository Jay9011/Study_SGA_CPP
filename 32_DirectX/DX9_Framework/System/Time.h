#pragma once

class Time
{
public:
	Time();
	~Time();

	void Update();
	void Render();

	UINT GetFPS() { return frameRate; }

	static double Delta() { return timeElapsed; }

private:
	//1�����Ӵ� ��� �ð�
	static double timeElapsed;

	double timeScale; //1tick�� �ɸ��� �ð�

	INT64  curTick;
	INT64 lastTick;
	INT64 ticksPerSecond;

	UINT frameCount;
	UINT frameRate;

	double oneSecCount;

	double runningTime;

	double scanningRate;

	//Text ���
	LPD3DXFONT font;
};
