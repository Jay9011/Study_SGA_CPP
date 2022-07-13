#pragma once
class Shader
{
public:
	Shader(wstring file);
	~Shader();

public:
	static Shader* Add(wstring file);

	static void Delete();

	void Begin(int _passIndex = 0);
	void End();

	void SetInt    (string _param, int   _data);
	void SetFloat  (string _param, float _data);
	void SetArray  (string _param, void* _data, int _count);
	void SetTexture(string _param, LPDIRECT3DTEXTURE9 _texture);

private:
	LPD3DXEFFECT shader;

	static map<wstring, Shader*> shaders;
};
