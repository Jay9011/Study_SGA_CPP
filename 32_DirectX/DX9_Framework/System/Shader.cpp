#include "Framework.h"
#include "Shader.h"

map<wstring, Shader*> Shader::shaders = {};

Shader::Shader(wstring file)
{
	D3DXCreateEffectFromFile(DEVICE, file.c_str(), nullptr, nullptr, D3DXSHADER_DEBUG, nullptr, &shader, nullptr);
}

Shader::~Shader()
{
	shader->Release();
}

Shader* Shader::Add(wstring file)
{
	file = L"Shaders/" + file + L".hlsl";

	if (shaders.count(file) > 0)
		return shaders[file];

	shaders.emplace(file, new Shader(file));

	return shaders[file];
}

void Shader::Delete()
{
	for (pair<wstring, Shader*> pair : shaders)
		delete pair.second;
}

void Shader::Begin(int _passIndex)
{
	shader->Begin(nullptr, 0);
	shader->BeginPass(_passIndex);
}

void Shader::End()
{
	shader->EndPass();
	shader->End();
}

void Shader::SetInt(string _param, int _data)
{
	shader->SetInt(_param.c_str(), _data);
}

void Shader::SetFloat(string _param, float _data)
{
	shader->SetFloat(_param.c_str(), _data);
}

void Shader::SetArray(string _param, void* _data, int _count)
{
	shader->SetFloatArray(_param.c_str(), (float*)_data, _count);
}

void Shader::SetTexture(string _param, LPDIRECT3DTEXTURE9 _texture)
{
	shader->SetTexture(_param.c_str(), _texture);
}
