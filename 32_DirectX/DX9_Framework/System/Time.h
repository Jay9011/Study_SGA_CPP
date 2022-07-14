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
	//1프레임당 경과 시간
	static double timeElapsed;

	double timeScale; //1tick에 걸리는 시간

	INT64  curTick;
	INT64 lastTick;
	INT64 ticksPerSecond;

	UINT frameCount;
	UINT frameRate;

	double oneSecCount;

	double runningTime;

	double scanningRate;

	//Text 출력
	LPD3DXFONT font;
};
