#pragma once
class Time
{
private:
	Time();
	~Time();

public:
	static void Create();
	static void Delete();

	static Time* Get();

	static double Delta() { return timeElapsed; }

	void Update();
	void Render();

	UINT GetFPS() { return frameRate; }

private:
	static Time* instance;

	// 1프레임당 경과 시간
	static double timeElapsed;

	INT64 curTick;
	INT64 lastTick;
	INT64 ticksPerSecond;

	UINT frameCount;
	UINT frameRate;

	double oneSecCount;
	double runningTime;
};

