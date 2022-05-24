#pragma once

class Animation
{
public:
	Animation(Texture* texture, double updateTime = 0.1);
	~Animation();

	void Update();

	// ù �����Ӻ��� �� �����ӱ��� ���� ����ϵ��� ����
	void SetDefault(bool isLoop = false);
	// �Ϻ� �����ӵ鸸 ����ϵ��� ����
	void SetPart(UINT start, UINT end, bool isLoop = false);

	void Play()
	{
		isPlay = true;
		curPlayIndex = 0;
	}
	void Stop()
	{
		isPlay = false;
	}

	/*
		Get / Set
	*/

	void SetUpdateTime(double updateTime) { this->updateTime = updateTime; }
	POINT GetFrame() { return frames[actions[curPlayIndex]]; }

private:
	vector<POINT>	frames;
	vector<UINT>	actions;

	UINT curPlayIndex;
	UINT maxPlayIndex;

	POINT maxFrame;

	bool isPlay;
	bool isLoop;

	double time;
	double updateTime;

};

