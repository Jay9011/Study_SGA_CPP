#pragma once

#define MAX_CHNNEL 10

struct SoundInfo
{
	SoundInfo()
		: sound(nullptr), channel(nullptr)
	{}
	~SoundInfo()
	{
		sound->release();
	}

	Sound* sound;
	Channel* channel;
};

class SoundManager
{
private:
	SoundManager();
	~SoundManager();

public:
	static void Create();
	static void Delete();

	static SoundManager* Get();

private:
	static SoundManager* instance;

public:
	void Update();

	void AddSound(string key, string file, bool stream);

	void Play  (string key, float volume = 1.f);
	void Stop  (string key);
	void Pause (string key);
	void Resume(string key);

private:
	map<string, SoundInfo*> sounds;
	System* system;

};
