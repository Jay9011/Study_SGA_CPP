#pragma once

/*
*	디자인 패턴 (Design Pattern)
*	 - 싱글톤 패턴 (Singleton)	( 인스턴스를 전역변수처럼 사용하는 방법. )
*
*	객체의 인스턴스를 오직 한 번만 생성한다.
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

private:
	static TextureManager* instance;

	map<string, Texture*>  textures;
};
