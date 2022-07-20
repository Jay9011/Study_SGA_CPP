#include "Framework.h"
#include "VertexShaderScene.h"

VertexShaderScene::VertexShaderScene()
{
	IDLE = new Object(L"Textures/IDLE.jpg");
	IDLE->SetShader(Shader::Add(L"VertexShader"));
	IDLE->pos = { WIN_CENTER_X, WIN_CENTER_Y };

	camera = new Camera;
}

VertexShaderScene::~VertexShaderScene()
{
	delete IDLE;
	delete camera;
}

void VertexShaderScene::Update()
{
	IDLE->Update();
	camera->Update();
}

void VertexShaderScene::Render()
{
	IDLE->GetShader()->SetMatrix("world", IDLE->GetWorld());
	IDLE->GetShader()->SetMatrix("view", camera->GetWorld());
	Matrix projection = Device::Get()->GetProjection();
	IDLE->GetShader()->SetMatrix("projection", &projection);

	IDLE->Render();
}
