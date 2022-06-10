#pragma once

class EffectScene : public Scene
{
public:
	EffectScene();
	~EffectScene();

	// Scene��(��) ���� ��ӵ�
	virtual void Update() override;
	virtual void Render(HDC hdc) override;

private:
	//CEffect* effect;
	Object* mountain;
	Knight* knight;

	// Sound
	System*  system;	// �Ҹ��� ���õ� �ý��� ����
	Sound*   sound;		// �Ҹ��� �����͸� ����/�ؼ�
	Channel* channel;	// �Ҹ��� ��� ü�� ����

};
