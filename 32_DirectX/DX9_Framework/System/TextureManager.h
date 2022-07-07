#pragma once
class TextureManager
{
public:
	TextureManager();
	~TextureManager();

	Texture* Add(wstring path, Vector2 start = { 0.f, 0.f }, Vector2 end = { 0.f, 0.f }, Vector2 pivot = { .5f, .5f });
	Texture* Add(wstring path, int maxFrameX, int maxFrameY, int frameX, int frameY, Vector2 pivot = { .5f, .5f });

	LPDIRECT3DTEXTURE9 LoadTexture(wstring path);

private:
	map<wstring, LPDIRECT3DTEXTURE9> textureMap;

	vector<Texture*> textures;

};
