#include "Framework.h"
#include "SoundManager.h"

SoundManager* SoundManager::instance = nullptr;

SoundManager::SoundManager()
{
	System_Create(&system);
	system->init(MAX_CHNNEL, FMOD_INIT_NORMAL, nullptr);
}

SoundManager::~SoundManager()
{
	for (pair<string, SoundInfo*> sound : sounds)
	{
		delete sound.second;
	}
	sounds.clear();
}

void SoundManager::Create()
{
	if (instance == nullptr)
		instance = new SoundManager;
}

void SoundManager::Delete()
{
	delete instance;
}

SoundManager* SoundManager::Get()
{
	if (instance == nullptr)
		Create();

	return instance;
}

void SoundManager::Update()
{
	system->update();
}

void SoundManager::AddSound(string key, string file, bool stream)
{
	SoundInfo* info = new SoundInfo;

	if (stream)
	{
		system->createStream(file.c_str(), FMOD_LOOP_NORMAL, nullptr, &info->sound);
	}
	else
	{
		system->createSound(file.c_str(), FMOD_DEFAULT, nullptr, &info->sound);
	}

	sounds.emplace(key, info);
}

void SoundManager::Play(string key, float volume)
{
	if (sounds.count(key) == 0)
		return;

	system->playSound(sounds[key]->sound, nullptr, false, &sounds[key]->channel);

	sounds[key]->channel->setVolume(volume);
}

void SoundManager::Stop(string key)
{
	if (sounds.count(key) == 0)
		return;

	sounds[key]->channel->stop();
}

void SoundManager::Pause(string key)
{
	if (sounds.count(key) == 0)
		return;

	sounds[key]->channel->setPaused(true);
}

void SoundManager::Resume(string key)
{
	if (sounds.count(key) == 0)
		return;

	sounds[key]->channel->setPaused(false);
}
