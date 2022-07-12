#include "Framework.h"
#include "MainGame.h"

MainGame::MainGame()
{
	DEVICE->SetRenderState(D3DRS_CULLMODE, D3DCULL_NONE);

	//scene = new VertexScene;
	//scene = new WVPScene;
	//scene = new SolarSystemScene;
	//scene = new TextureScene;
	//scene = new CollisionScene;
	//scene = new AnimationScene;
	scene = new ShaderScene;
}

MainGame::~MainGame()
{
	delete scene;
}

void MainGame::Update()
{
	if (KEYDOWN(VK_TAB))
		Collider::HiddenInGame();

	scene->Update();
}

void MainGame::Render()
{
	scene->Render();
}
