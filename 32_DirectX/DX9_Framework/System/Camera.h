#pragma once
class Camera : public Transform
{
public:
	Camera();
	~Camera();

	void Update();

	void FreeMode();
	void TargetMode();

	void SetTarget(Transform* target) { this->target = target; }
	void SetBackground(Object* background) 
	{ 
		this->background = background;
		bgLT = background->pos - background->GetTexture()->GetSize() * 0.5;
		bgRB = background->pos + background->GetTexture()->GetSize() * 0.5;
	}

private:
	float speed;

	Transform* target;
	Object* background;
	
	Vector2 offset;
	Vector2 bgLT;
	Vector2 bgRB;

};

