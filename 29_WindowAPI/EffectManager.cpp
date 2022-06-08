#include "Framework.h"
#include "EffectManager.h"

EffectManager* EffectManager::instance = nullptr;

EffectManager::EffectManager() = default;

EffectManager::~EffectManager()
{
	for (pair<string, vector<CEffect*>> pair : effectMap)
	{
		for (CEffect* effect : pair.second)
			delete effect;
	}
	effectMap.clear();
}

void EffectManager::Create()
{
	if (instance == nullptr)
		instance = new EffectManager();
}

void EffectManager::Delete()
{
	delete instance;
}

EffectManager* EffectManager::Get()
{
	if (instance == nullptr)
		Create();

	return instance;
}

void EffectManager::Update()
{
	for (pair<string, vector<CEffect*>> pair : effectMap)
	{
		for (CEffect* effect : pair.second)
			effect->Update();
	}
}

void EffectManager::Render()
{
	for (pair<string, vector<CEffect*>> pair : effectMap)
	{
		for (CEffect* effect : pair.second)
			effect->Render();
	}
}

void EffectManager::AddEffect(string key, Texture* texture, UINT poolCount, double speed)
{
	vector<CEffect*> effects;

	for (UINT i = 0; i < poolCount; i++)
	{
		effects.push_back(new CEffect(texture, speed));
	}

	effectMap.emplace(key, effects);
}

void EffectManager::Play(string key, Vector2 pos)
{
	if (effectMap.count(key) == 0)
		return;

	for (CEffect* effect : effectMap[key])
	{
		if (!effect->IsActive())
		{
			effect->Play(pos);
			return;
		}
	}
}
