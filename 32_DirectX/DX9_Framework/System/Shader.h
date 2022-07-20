#pragma once

class Shader
{
private:
	Shader(wstring file);
	~Shader();

public:
	static Shader* Add(wstring file);

	static void Delete();

	void Begin(int passIndex = 0);
	void End();

	void SetInt    (string param, int   data);
	void SetFloat  (string param, float data);
	void SetArray  (string param, void* data, int count);
	void SetTexture(string param, LPDIRECT3DTEXTURE9 texture);
	void SetMatrix (string param, Matrix* matrix);

private:
	LPD3DXEFFECT shader;

	static map<wstring, Shader*> shaders;
};
