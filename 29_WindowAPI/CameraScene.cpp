#include "Framework.h"
#include "CameraScene.h"

CameraScene::CameraScene()
{
	Camera::Create();

	bgTex = TextureManager::Get()->AddTexture("Mountain", L"Textures/mountain_large.bmp");
	bg = new Object(bgTex);

	missile = new Missile();

	Camera::Get()->SetTarget(missile);
}

CameraScene::~CameraScene()
{
	Camera::Delete();
	delete missile;
}

void CameraScene::Update()
{
	Camera::Get()->Update();
	missile->Update();
}

void CameraScene::Render(HDC hdc)
{
	bg->Render(Camera::Get()->Pos());
	missile->Render();
}
