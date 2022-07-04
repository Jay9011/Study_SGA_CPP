#pragma once
class CollisionScene : public IScene
{
public:
	CollisionScene();
	~CollisionScene();

	// IScene��(��) ���� ��ӵ�
	virtual void Update() override;
	virtual void Render() override;

private:
	Texture*     idleTexture;
	Transform    idleTransform;
	ColliderBox* idleCollider;


};
