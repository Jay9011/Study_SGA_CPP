#pragma once
class AnimationScene : public IScene
{
public:
	AnimationScene();
	~AnimationScene();

	// IScene을(를) 통해 상속됨
	virtual void Update() override;
	virtual void Render() override;

private:
	Mario* mario;
};
