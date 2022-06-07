#pragma once

class Animation
{
public:
	Animation(double updateTime = 0.1);
	Animation(Texture* texture, double updateTime = 0.1);
	~Animation();

	void Update();

	// ù �����Ӻ��� �� �����ӱ��� ���� ����ϵ��� ����
	void SetDefault(bool isLoop = false, bool isRewind = false);
	// �Ϻ� �����ӵ鸸 ����ϵ��� ����
	void SetPart(UINT start, UINT end, bool isLoop = false, bool isRewind = false);
	// Ư�� �����ӵ鸸 ����ϵ��� ����
	void SetVector(vector<UINT> vector, bool isLoop = false, bool isRewind = false);

	void SetRewind();

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
	bool  IsPlay()   const					  { return isPlay; }
	bool& IsLoop()							  { return isLoop; }
	bool& IsRewind()                          { return isRewind; }

	void  SetUpdateTime(double updateTime)	  { this->updateTime = updateTime; }
	POINT GetFrame() const					  { return frames[actions[curPlayIndex]]; }

	void SetEndEvent (function<void()> _func)    { this-> EndEvent = _func; }
	void SetNextEvent(function<void(int)> _func) { this-> NextEvent = _func; }
	void SetNextIndex(int _index)				 { nextIndex = _index; }

	RECT GetXMLFrame() { return xmlFrames[curPlayIndex]; }
	void SetXMLFrame(int left, int top, int width, int height);
	
private:
	vector<POINT>	frames;
	vector<UINT>	actions;

	vector<RECT>	xmlFrames;

	UINT curPlayIndex;
	UINT maxPlayIndex;

	POINT maxFrame;

	bool isPlay;
	bool isLoop;
	bool isRewind;

	double time;
	double updateTime;

	int nextIndex;

	function<void()>    EndEvent;
	function<void(int)> NextEvent;
};

