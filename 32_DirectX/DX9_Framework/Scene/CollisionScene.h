#pragma once

class CollisionScene : public Scene
{
public:
	CollisionScene();
	~CollisionScene();

	virtual void Update() override;
	virtual void Render() override;

private:
	Texture*     idleTexture;
	Transform    idleTransform;
	ColliderBox* idleCollider;

	Texture*     idle2Texture;
	Transform    idle2Transform;
	//ColliderBox* idle2Collider;
	ColliderCircle* idle2Collider;
};
