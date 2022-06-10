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

	// Sound
	System*  system;	// 소리와 관련된 시스템 구축
	Sound*   sound;		// 소리의 데이터를 저장/해석
	Channel* channel;	// 소리의 출력 체널 조정

};
