#pragma once

class EffectScene : public Scene
{
public:
	EffectScene();
	~EffectScene();

	// Scene을(를) 통해 상속됨
	virtual void Update() override;
	virtual void Render(HDC hdc) override;

private:
	//CEffect* effect;
	Object* mountain;
	Knight* knight;
};
