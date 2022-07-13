#include "Framework.h"
#include "ShaderScene.h"

ShaderScene::ShaderScene() :
	color(1.0f, 0.0f, 0.0f, 1.0f)
{
	texture = TEXTURE->Add(L"Textures/IDLE.jpg");

	transform.pos = { WIN_CENTER_X, WIN_CENTER_Y };

	D3DXCreateEffectFromFile(DEVICE, L"Shaders/AlphaShader.hlsl", nullptr, nullptr, D3DXSHADER_DEBUG, nullptr, &shader, nullptr);

	TwBar* bar = TweakBar::Get()->GetBar();
	TwAddVarRW(bar, "Color", TW_TYPE_COLOR4F, &color, "");

	airplane = TEXTURE->Add(L"Textures/airplane.png");
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

	texture->Render();

	shader->SetFloatArray("Color", (float*)&color, 4);

	shader->Begin(nullptr, 0);
	shader->BeginPass(0);
	// Shader 적용 시작

	airplane->Render();

	// Shader 적용 끝
	shader->EndPass();
	shader->End();
}
