#include "Framework.h"
#include "MultiShaderScene.h"

MultiShaderScene::MultiShaderScene()
{
	mario = new Mario;
}

MultiShaderScene::~MultiShaderScene()
{
	delete mario;
}

void MultiShaderScene::Update()
{
	mario->Update();
}

void MultiShaderScene::Render()
{
	mario->Render();
}

