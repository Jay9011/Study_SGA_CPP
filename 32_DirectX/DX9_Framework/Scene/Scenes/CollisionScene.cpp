#include "Framework.h"
#include "CollisionScene.h"

CollisionScene::CollisionScene()
{
	idleTexture = TEXTURE->Add(L"Textures/IDLE.jpg");
	idleCollider = new ColliderBox({ 750, 500 }, &idleTransform);
}

CollisionScene::~CollisionScene()
{
	if (idleCollider != nullptr)
	{
		delete idleCollider;
		idleCollider = nullptr;
	}
}

void CollisionScene::Update()
{
	Manager::Get()->GetKeyboard()->Move(idleTransform, 5.f);

	if (idleCollider->Collision(mousePos))
		idleTransform.angle += 0.01f;

	idleTransform.UpdateWorld();
	idleCollider->Update();
}

void CollisionScene::Render()
{
	idleTransform.SetWorld();
	idleTexture->Render();

	idleCollider->Render();
}
