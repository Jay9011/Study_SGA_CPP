#include "Framework.h"
#include "CollisionScene.h"

CollisionScene::CollisionScene()
{
	idle = TEXTURE->Add(L"Textures/IDLE.jpg");
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
	idleTransform.UpdateWorld();
	idleCollider->Update();

	Manager::Get()->GetKeyboard()->Move(idleTransform, 5.f);

	if (idleCollider->Collision(mousePos))
		idleTransform.angle += 1.f;
}

void CollisionScene::Render()
{
	idleTransform.SetWorld();
	idleCollider->Render();
	idle->Render();
}
