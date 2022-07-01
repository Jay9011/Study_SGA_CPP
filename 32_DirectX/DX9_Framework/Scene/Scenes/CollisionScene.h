#pragma once
class CollisionScene : public IScene
{
public:
	CollisionScene();
	~CollisionScene();

	// IScene을(를) 통해 상속됨
	virtual void Update() override;
	virtual void Render() override;

private:
	Texture*     idle;
	Transform    idleTransform;
	ColliderBox* idleCollider;


};
