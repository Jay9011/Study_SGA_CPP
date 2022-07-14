#pragma once

class EffectManager
{
public:
	EffectManager();
	~EffectManager();

	void Update();
	void Render();

	void Add
	(
		string  key, 
		wstring path, 
		UINT    poolCount, 
		int     maxFrameX, 
		int     maxFrameY, 
		bool    isAdditive = true, 
		float   speed      = 0.1f
	);

	void Play(string key, Vector2 pos, D3DXCOLOR color = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f));

private:
	map<string, vector<Effect*>> effectMap;
};
