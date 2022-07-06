#include "Framework.h"
#include "TextureManager.h"

TextureManager::TextureManager()
{
}

TextureManager::~TextureManager()
{
	for (pair<wstring, Texture*> pair : textures)
	{
		delete pair.second;
	}
	textures.clear();
}

Texture* TextureManager::Add(wstring path, Vector2 start, Vector2 end, Vector2 pivot)
{
	if (textures.count(path) > 0)
		return textures[path];

	Texture* tex = nullptr;

	LPDIRECT3DTEXTURE9 texture;

	D3DXCreateTextureFromFileEx
	(
		DEVICE,
		path.c_str(),
		D3DX_DEFAULT_NONPOW2,
		D3DX_DEFAULT_NONPOW2,
		D3DX_FROM_FILE,
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
	
	tex = new Texture(texture, start, end, pivot);
	textures.emplace(path, tex);

	return tex;
}

Texture* TextureManager::Add(wstring path, int maxFrameX, int maxFrameY, int frameX, int frameY, Vector2 pivot)
{
	if (textures.count(path) > 0)
		return textures[path];

	Texture* tex = nullptr;

	LPDIRECT3DTEXTURE9 texture;

	D3DXCreateTextureFromFileEx
	(
		DEVICE,
		path.c_str(),
		D3DX_DEFAULT_NONPOW2,
		D3DX_DEFAULT_NONPOW2,
		D3DX_FROM_FILE,
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

	tex = new Texture(texture, maxFrameX, maxFrameY, frameX, frameY, pivot);
	textures.emplace(path, tex);

	return tex;
}
