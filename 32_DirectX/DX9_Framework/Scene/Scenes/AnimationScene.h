#pragma once
class AnimationScene : public IScene
{
public:
	AnimationScene();
	~AnimationScene();

	// IScene��(��) ���� ��ӵ�
	virtual void Update() override;
	virtual void Render() override;

private:
	Mario* mario;
};
