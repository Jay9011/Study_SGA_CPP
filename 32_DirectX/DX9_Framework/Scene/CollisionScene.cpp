#include "Framework.h"
#include "CollisionScene.h"

CollisionScene::CollisionScene()
{
	idleTexture = TEXTURE->Add(L"Textures/IDLE.jpg");
	idleTransform.pos = { 0, 300 };
	idleCollider = new ColliderBox({ 750, 500 }, &idleTransform);
	//idleCollider->SetOffset({ 50, 0 });

	idle2Texture = TEXTURE->Add(L"Textures/IDLE.jpg");
	idle2Transform.pos = { WIN_WIDTH * 0.8, WIN_CENTER_Y };
	//idle2Collider = new ColliderBox({ 750, 500 }, &idle2Transform);
	idle2Collider = new ColliderCircle(50.0f, &idle2Transform);
}

CollisionScene::~CollisionScene()
{
	delete idleCollider;
}

void CollisionScene::Update()
{
	Manager::Get()->GetKeyboard()->Move(&idleTransform, 100.0f);


	idleTransform.UpdateWorld();
	idleCollider->Update();

	idle2Transform.UpdateWorld();
	idle2Collider->Update();


	if (idle2Collider->Collision(idleCollider))
		idleTransform.angle += 0.01f;
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
