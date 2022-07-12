#include "Framework.h"
#include "ShaderScene.h"

ShaderScene::ShaderScene() :
	color(1.0f, 0.0f, 0.0f, 1.0f)
{
	texture = TEXTURE->Add(L"Textures/IDLE.jpg");

	transform.pos = { WIN_CENTER_X, WIN_CENTER_Y };

	D3DXCreateEffectFromFile(DEVICE, L"Shaders/Test.hlsl", nullptr, nullptr, D3DXSHADER_DEBUG, nullptr, &shader, nullptr);

	TwBar* bar = TweakBar::Get()->GetBar();
	TwAddVarRW(bar, "Color", TW_TYPE_COLOR4F, &color, "");
}

ShaderScene::~ShaderScene()
{
	shader->Release();
}

void ShaderScene::Update()
{
	transform.UpdateWorld();
}

void ShaderScene::Render()
{
	transform.SetWorld();

	shader->SetFloatArray("Color", (float*)&color, 4);

	shader->Begin(nullptr, 0);
	shader->BeginPass(0);

	texture->Render();

	shader->EndPass();
	shader->End();
}
