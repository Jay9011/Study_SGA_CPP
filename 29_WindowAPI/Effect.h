#pragma once
class CEffect
{
public:
	CEffect(Texture* texture, double speed = 0.1);
	~CEffect();

	void  Update();
	void  Render();
		  
	void  Play(Vector2 pos);
	void  Stop();

	bool& IsActive() { return isActive; }

private:
	Animation* animation;
	Texture*   texture;
	Rect*      rect;

	bool       isActive;

};

