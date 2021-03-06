#include "Framework.h"
#include "TextureManager.h"

TextureManager* TextureManager::instance = nullptr;

TextureManager::TextureManager()
{
}

TextureManager::~TextureManager()
{
	for (pair<string, Texture*> texture : textures)
		delete texture.second;
}

void TextureManager::Create()
{
	if (instance == nullptr)
	{
		instance = new TextureManager;
	}
}

void TextureManager::Delete()
{
	if (instance != nullptr)
	{
		delete instance;
	}
}

TextureManager* TextureManager::Get()
{
	//if (instance == nullptr)
	//{
	//	instance = new TextureManager;
	//}

	return instance;
}

Texture* TextureManager::AddTexture(string key, wstring path, Gdiplus::Color transColor)
{
	if (textures.count(key) > 0)
		return textures[key];

	Texture* texture = new Texture(path, transColor);
	//textures.insert(pair<string, Texture*>(key, texture));
	//textures.insert({ key, texture });
	textures.emplace(key, texture);

	return texture;
}

Texture* TextureManager::AddTexture(string key, wstring path, long frameX, long frameY, Gdiplus::Color transColor)
{
	if (textures.count(key) > 0)
		return textures[key];

	Texture* texture = new Texture(path, frameX, frameY, transColor);
	textures.emplace(key, texture);

	return texture;
}
