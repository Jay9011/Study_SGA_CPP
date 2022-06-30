#pragma once
class TextureManager
{
public:
	TextureManager();
	~TextureManager();

	Texture* Add(wstring path, Vector2 start = { 0.f, 0.f }, Vector2 end = { 0.f, 0.f }, Vector2 pivot = { .5f, .5f });

private:
	map<wstring, Texture*> textures;

};
