#include "Framework.h"
#include "ShaderScene.h"

ShaderScene::ShaderScene()
	:color(1, 1, 1, 1), passIndex(0)
{
	texture = TEXTURE->Add(L"Textures/IDLE.jpg");

	transform.pos = { WIN_CENTER_X, WIN_CENTER_Y };

	D3DXCreateEffectFromFile(DEVICE, L"Shaders/GrayScaleShader.hlsl", nullptr, nullptr, D3DXSHADER_DEBUG,
		nullptr, &shader, nullptr);

	TwBar* bar = TweakBar::Get()->GetBar();
	TwAddVarRW(bar, "Color",     TW_TYPE_COLOR4F, &color,     "");
	TwAddVarRW(bar, "PassIndex", TW_TYPE_INT32,   &passIndex, "");


	airplane = TEXTURE->Add(L"Textures/airplane.png");

	EFFECTS->Add("Effect3", L"effect3.png", 30, 5, 3);
}

ShaderScene::~ShaderScene()
{
	shader->Release();
}

void ShaderScene::Update()
{
	if (KEYDOWN(VK_LBUTTON))
	{
		EFFECTS->Play("Effect3", mousePos);
	}

	transform.UpdateWorld();
}

void ShaderScene::Render()
{
	transform.SetWorld();

	texture->Render();

	shader->SetFloatArray("Color", (float*)&color, 4);

	shader->Begin(nullptr, 0);
	shader->BeginPass(passIndex);

	airplane->Render();

	shader->EndPass();
	shader->End();
}
