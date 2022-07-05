#include "Framework.h"
#include "CollisionScene.h"

CollisionScene::CollisionScene()
{
	idleTexture = TEXTURE->Add(L"Textures/IDLE.jpg");
	//idleCollider = new ColliderBox({ 750, 500 }, &idleTransform);
	idleCollider = new ColliderCircle(250.f, &idleTransform);
	idleCollider->SetOffset({ 50, 0 });
	
	idle2Texture = TEXTURE->Add(L"Textures/IDLE.jpg");
	idle2Transform.pos = { WIN_WIDTH * 0.8, WIN_HEIGHT * 0.8 };
	//idle2Collider = new ColliderBox({ 750, 500 }, &idle2Transform);
	idle2Collider = new ColliderCircle(250.f, &idle2Transform);
}

CollisionScene::~CollisionScene()
{
	if (idleCollider != nullptr)
	{
		delete idleCollider;
		idleCollider = nullptr;
	}

	if (idle2Collider != nullptr)
	{
		delete idle2Collider;
		idle2Collider = nullptr;
	}
}

void CollisionScene::Update()
{
	Manager::Get()->GetKeyboard()->Move(idleTransform, 5.f);

	if (idle2Collider->Collision(idleCollider))
		idleTransform.angle += 0.01f;

	idleTransform.UpdateWorld();
	idleCollider->Update();

	idle2Transform.UpdateWorld();
	idle2Collider->Update();
}

void CollisionScene::Render()
{
	idleTransform.SetWorld();
	idleTexture->Render();

	idle2Transform.SetWorld();
	idle2Texture->Render();

	idleCollider->Render();
	idle2Collider->Render();
}
