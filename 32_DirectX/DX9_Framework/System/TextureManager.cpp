#include "Framework.h"
#include "TextureManager.h"

TextureManager::TextureManager()
{
}

TextureManager::~TextureManager()
{
	for (pair<wstring, LPDIRECT3DTEXTURE9> pair : textureMap)
		pair.second->Release();

	for (Texture* texture : textures)
		delete texture;

	textureMap.clear();
	  textures.clear();
}

Texture* TextureManager::Add(wstring path, Vector2 start, Vector2 end, Vector2 pivot)
{	
	Texture* tex = new Texture(LoadTexture(path), start, end, pivot);

	textures.push_back(tex);

	return tex;
}

Texture* TextureManager::Add(wstring path, int maxFrameX, int maxFrameY, int frameX, int frameY, Vector2 pivot)
{	
	Texture* tex = new Texture(LoadTexture(path), maxFrameX, maxFrameY, frameX, frameY, pivot);

	textures.push_back(tex);

	return tex;
}

LPDIRECT3DTEXTURE9 TextureManager::LoadTexture(wstring path)
{
	if (textureMap.count(path) > 0)
		return textureMap[path];

	LPDIRECT3DTEXTURE9 texture;

	D3DXCreateTextureFromFileEx
	(
		DEVICE,
		path.c_str(),
		D3DX_DEFAULT_NONPOW2,
		D3DX_DEFAULT_NONPOW2,
		1,
		0,
		D3DFMT_A8R8G8B8,
		D3DPOOL_DEFAULT,
		D3DX_FILTER_NONE,
		D3DX_FILTER_NONE,
		0xFFFF00FF,
		nullptr,
		nullptr,
		&texture
	);

	textureMap.emplace(path, texture);

	return texture;
}
