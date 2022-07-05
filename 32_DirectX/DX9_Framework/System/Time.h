#pragma once
class Time
{
public:
	Time();
	~Time();

public:
	static double Delta() { return timeElapsed; }

	void Update();
	void Render();

	UINT GetFPS() { return frameRate; }

private:
	// 1프레임당 경과 시간
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
	double scanningRate; // 주사율
};

