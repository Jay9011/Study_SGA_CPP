#pragma once

/*
*	������ ���� (Design Pattern)
*	 - �̱��� ���� (Singleton)	( �ν��Ͻ��� ��������ó�� ����ϴ� ���. )
*
*	��ü�� �ν��Ͻ��� ���� �� ���� �����Ѵ�.
*/

class TextureManager
{
private:
	TextureManager();
	~TextureManager();

public:
	static void Create();
	static void Delete();

	static TextureManager* Get();

	Texture* AddTexture(string key, wstring path, Gdiplus::Color transColor = Gdiplus::Color::Magenta);
	Texture* AddTexture(string key, wstring path, long frameX, long frameY, Gdiplus::Color transColor = Gdiplus::Color::Magenta);

	Texture* AddBitMap(string key, wstring _file, long _width, long _height, COLORREF _transColor = COLOR_MAGENTA);
	Texture* AddBitMap(string key, wstring _file, long _width, long _height, long _frameX, long _frameY, COLORREF _transColor = COLOR_MAGENTA);

	Texture* Find(string key);

	void DeleteTexture(string key);

private:
	static TextureManager* instance;

	map<string, Texture*>  textures;
};
