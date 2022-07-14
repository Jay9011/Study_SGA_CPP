#include "Framework.h"
#include "Animation.h"

Animation::Animation(vector<Texture*> actions, Type type, float speed)
	:actions(actions), type(type), speed(speed), 
	curPlayIndex(0), isPlay(false), isReverse(false), time(0.0f), EndEvent(nullptr)
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
		time = 0.0f;

		switch (type)
		{
		case END:
			curPlayIndex++;
			if (curPlayIndex >= actions.size())
				Stop();
			break;
		case LOOP:
			++curPlayIndex %= actions.size();
			break;
		case PINGPONG:
			if (!isReverse)
			{
				curPlayIndex++;
				if (curPlayIndex >= actions.size() - 1)
					isReverse = true;
			}
			else
			{
				curPlayIndex--;
				if (curPlayIndex <= 0)
					isReverse = false;
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
	curPlayIndex = 0;
	time = 0.0f;
	isReverse = false;
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
		curPlayIndex = 0;
		EndEvent();
	}
	else
	{
		curPlayIndex--;
	}
}
