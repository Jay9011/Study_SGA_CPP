#pragma once

class EffectManager
{
private:
	EffectManager();
	~EffectManager();

public:
	static void Create();
	static void Delete();

	static EffectManager* Get();

	void Update();
	void Render();

	void AddEffect(string key, Texture* texture, UINT poolCount, double speed = 0.1);

	void Play(string key, Vector2 pos);

private:
	static EffectManager* instance;

	map<string, vector<CEffect*>> effectMap;

};
