#include "Framework.h"
#include "Animation.h"

Animation::Animation(Texture* texture, double updateTime)
	: curPlayIndex(0)
	, isPlay(false)
	, isLoop(false)
	, time(0)
	, updateTime(updateTime)
{
	maxFrame = texture->GetMaxFrame();
	maxPlayIndex = maxFrame.x * maxFrame.y;

	for (int j = 0; j < maxFrame.y; j++)
	{
		for (int i = 0; i < maxFrame.x; i++)
		{
			frames.push_back({ i, j });
		}
	}
}

Animation::~Animation() = default;

void Animation::Update()
{
	if (!isPlay)
		return;

	time += Time::Delta();

	if (time > updateTime)
	{
		time = 0;
		++curPlayIndex;

		if (curPlayIndex > (actions.size() - 1))
		{
			if (isLoop)
			{
				curPlayIndex = 0;
			}
			else
			{
				curPlayIndex = actions.size() - 1;
				isPlay = false;
			}
		}
	}
}

void Animation::SetDefault(bool isLoop)
{
	actions.clear();

	this->isLoop = isLoop;

	for (UINT i = 0; i < maxPlayIndex; i++)
	{
		actions.push_back(i);
	}
}

void Animation::SetPart(UINT start, UINT end, bool isLoop)
{
	actions.clear();

	this->isLoop = isLoop;

	for (UINT i = start; i <= end; i++)
	{
		actions.push_back(i);
	}
}
