#include "Framework.h"
#include "EffectManager.h"

EffectManager::EffectManager()
{
}

EffectManager::~EffectManager()
{
	for (pair<string, vector<Effect*>> pair : effectMap)
	{
		for (Effect* effect : pair.second)
			delete effect;
	}

}

void EffectManager::Update()
{
	for (pair<string, vector<Effect*>> pair : effectMap)
	{
		for (Effect* effect : pair.second)
			effect->Update();
	}
}

void EffectManager::Render()
{
	for (pair<string, vector<Effect*>> pair : effectMap)
	{
		for (Effect* effect : pair.second)
			effect->Render();
	}
}

void EffectManager::Add(string key, wstring path, UINT poolCount, int maxFrameX, int maxFrameY, bool isAdditive, float speed)
{
	if (effectMap.count(key) > 0)
		return;

	vector<Effect*> effects;

	for (UINT i = 0; i < poolCount; i++)
	{
		Effect* effect = new Effect(path, maxFrameX, maxFrameY, isAdditive, speed);
		effects.push_back(effect);
	}

	effectMap.emplace(key, effects);
}

void EffectManager::Play(string key, Vector2 pos, D3DXCOLOR color)
{
	if (effectMap.count(key) == 0)
		return;

	for (Effect* effect : effectMap[key])
	{
		if (!effect->IsActive())
		{
			effect->Play(pos, color);
			return;
		}
	}
}
