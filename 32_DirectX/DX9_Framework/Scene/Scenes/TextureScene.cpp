#include "Framework.h"
#include "TextureScene.h"

TextureScene::TextureScene()
{
	/*D3DXCreateTextureFromFile(DEVICE, L"Textures/IDLE.jpg", &texture);

	D3DSURFACE_DESC surface;
	texture->GetLevelDesc(0, &surface);
	
	UINT width  = surface.Width;
	UINT height = surface.Height;*/


	//D3DXIMAGE_INFO  info;
	//D3DXCreateTextureFromFileEx
	//(
	//	DEVICE,
	//	L"Textures/IDLE.jpg",
	//	D3DX_DEFAULT_NONPOW2,
	//	D3DX_DEFAULT_NONPOW2,
	//	D3DX_FROM_FILE,
	//	0,
	//	D3DFMT_A8R8G8B8,
	//	D3DPOOL_DEFAULT,
	//	D3DX_FILTER_NONE,
	//	D3DX_FILTER_NONE,
	//	0xFFFF00FF,
	//	&info,
	//	nullptr,
	//	&texture
	//);

	//int width  = info.Width;
	//int height = info.Height;

	//vertices.push_back(VertexTexture(-width * .5f, -height * .5f, 0.f, 0.f));
	//vertices.push_back(VertexTexture(+width * .5f, -height * .5f, 1.f, 0.f));
	//vertices.push_back(VertexTexture(-width * .5f, +height * .5f, 0.f, 1.f));
	//vertices.push_back(VertexTexture(+width * .5f, +height * .5f, 1.f, 1.f));

	//// index 로 도형 그리기 (공간 절약)
	//indices.push_back(0);
	//indices.push_back(1);
	//indices.push_back(2);
	//indices.push_back(2);
	//indices.push_back(1);
	//indices.push_back(3);

	IDLE = TEXTURE->Add(L"Textures/IDLE.jpg");
	transform.pos = { 400, 400 };
}

TextureScene::~TextureScene()
{
	texture->Release();
}

void TextureScene::Update()
{
	if (KEYPRESS(VK_LEFT))
		--transform.pos.x;
	if (KEYPRESS(VK_RIGHT))
		++transform.pos.x;
	if (KEYPRESS(VK_UP))
		--transform.pos.y;
	if (KEYPRESS(VK_DOWN))
		++transform.pos.y;

	if (KEYPRESS('I'))
		transform.angle -= 0.01f;
	if (KEYPRESS('K'))
		transform.angle += 0.01f;

	transform.UpdateWorld();
}

void TextureScene::Render()
{
	/*DEVICE->SetFVF(VertexTexture::fvf);
	DEVICE->SetTexture(0, texture);*/

	transform.SetWorld();

	IDLE->Render();

	/*DEVICE->DrawIndexedPrimitiveUP(
		D3DPT_TRIANGLELIST, 
		0, 
		vertices.size(), 
		indices.size() / 3, 
		indices.data(), 
		D3DFMT_INDEX32, 
		vertices.data(), 
		sizeof(VertexTexture)
	);*/
}
