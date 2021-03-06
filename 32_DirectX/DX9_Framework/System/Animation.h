#pragma once

enum Type
{
	END,
	LOOP,
	PINGPONG
};

class Animation
{
public:
	Animation(vector<Texture*> actions, Type type = LOOP, float speed = 0.1f);
	~Animation();

	void Update();
	void Render();

	void Play();
	void Pause();
	void Stop();

	void SetEndEvent(function<void()> EndEvent) { this->EndEvent = EndEvent; }

	Texture* GetCurAction() { return actions[curPlayIndex]; }

private:
	vector<Texture*> actions;

	Type type;

	bool isPlay;

	UINT curPlayIndex;
	
	float time;
	float speed;

	bool isReverse;

	function<void()> EndEvent;
};

