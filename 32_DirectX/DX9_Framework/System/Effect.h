#pragma once

class Effect : public Transform
{
public:
	Effect(wstring file, int maxFrameX, int maxFrameY, bool isAdditive = true, float speed = 0.1f);
	~Effect();

	void Update();
	void Render();

	void Play(Vector2 pos, D3DXCOLOR color);
	void End();

	bool& IsActive() { return isActive; }

private:
	Shader*    shader;
	Animation* animation;

	bool isActive;
	bool isAdditive;

	D3DXCOLOR color;
};
