#include "Framework.h"
#include "TextureScene.h"

TextureScene::TextureScene()
{
	D3DXCreateTextureFromFile(DEVICE, L"Textures/IDLE.jpg", &texture);

	D3DXIMAGE_INFO  info;
	D3DSURFACE_DESC surface;
	texture->GetLevelDesc(0, &surface);
	
	UINT width  = surface.Width;
	UINT height = surface.Height;

	vertices.push_back(VertexTexture(  0.f,    0.f, 0.f, 0.f));
	vertices.push_back(VertexTexture(width,    0.f, 1.f, 0.f));
	vertices.push_back(VertexTexture(  0.f, height, 0.f, 1.f));
	vertices.push_back(VertexTexture(width, height, 1.f, 1.f));

	// index 로 도형 그리기 (공간 절약)
	indices.push_back(0);
	indices.push_back(1);
	indices.push_back(2);
	indices.push_back(2);
	indices.push_back(1);
	indices.push_back(3);


}

TextureScene::~TextureScene()
{
}

void TextureScene::Update()
{
}

void TextureScene::Render()
{
	DEVICE->SetFVF(VertexTexture::fvf);
	DEVICE->SetTexture(0, texture);

	DEVICE->DrawIndexedPrimitiveUP(
		D3DPT_TRIANGLELIST, 
		0, 
		vertices.size(), 
		indices.size() / 3, 
		indices.data(), 
		D3DFMT_INDEX32, 
		vertices.data(), 
		sizeof(VertexTexture)
	);
}
