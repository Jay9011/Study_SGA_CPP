#pragma once

class TextureManager
{
public:
	TextureManager();
	~TextureManager();

	Texture* Add
	(
		wstring path, 
		Vector2 start = Vector2(0.0f, 0.0f), 
		Vector2   end = Vector2(0.0f, 0.0f), 
		Vector2 pivot = Vector2(0.5f, 0.5f)
	);

	Texture* Add
	(
		wstring path,
		int maxFrameX, int maxFrameY,
		int frameX, int frameY,
		Vector2 pivot = Vector2(0.5f, 0.5f)
	);

	LPDIRECT3DTEXTURE9 LoadTexture(wstring path);

private:
	map<wstring, LPDIRECT3DTEXTURE9> textureMap;

	vector<Texture*> textures;
};
