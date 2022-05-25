#pragma once
class AnimationScene : public Scene
{
public:
	AnimationScene();
	~AnimationScene() override;

	virtual void Update() override;
	virtual void Render(HDC hdc) override;

private:
	Animation* animation;
	
	Texture* texture;
	Rect* rect;

	Mario* mario;
};

