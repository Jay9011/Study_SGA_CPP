#include "Framework.h"
#include "Animation.h"

Animation::Animation(vector<Texture*> actions, Type type, float speed) :
	actions(actions)
	, type(type)
	, isPlay(false)
	, curPlayIndex(0)
	, time(0.f)
	, speed(speed)
	, isReverse(false)
	, EndEvent(nullptr)
{
}

Animation::~Animation()
{
}

void Animation::Update()
{
	if (!isPlay)
		return;

	time += Time::Delta();

	if (time > speed)
	{
		time = 0.f;

		/*
		* curPlayIndex Αυ°¨
		*/
		switch (type)
		{
		case END:
		{
			if (++curPlayIndex >= actions.size())
				Stop();
		}
			break;
		case LOOP:
		{
			++curPlayIndex %= actions.size();
		}
			break;
		case REVERSE:
		{
			if (!isReverse)
			{
				if (++curPlayIndex >= actions.size() - 1)
					isReverse = true;
			}
			else
			{
				if (--curPlayIndex <= 0)
					isReverse = false;
			}
		}
			break;
		default:
			break;
		}
	}
}

void Animation::Render()
{
	actions[curPlayIndex]->Render();
}

void Animation::Play()
{
	isPlay = true;
	isReverse = false;
	time = 0.f;
	curPlayIndex = 0;
}

void Animation::Pause()
{
	isPlay = false;
}

void Animation::Stop()
{
	isPlay = false;

	if (EndEvent != nullptr)
	{
		EndEvent();
		curPlayIndex = 0;
	}
	else
	{
		--curPlayIndex;
	}
}
