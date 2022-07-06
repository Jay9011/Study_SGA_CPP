#pragma once

enum Type
{
	END,
	LOOP,
	REVERSE
};

class Animation
{
public:
	Animation(vector<Texture*> actions, Type type = LOOP, float speed = .1f);
	~Animation();

	void Update();
	void Render();

	void Play();
	void Pause();
	void Stop();

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
