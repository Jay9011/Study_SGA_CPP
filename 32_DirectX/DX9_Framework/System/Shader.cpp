#include "Framework.h"
#include "Shader.h"

map<wstring, Shader*> Shader::shaders = {};

Shader::Shader(wstring file)
{
	D3DXCreateEffectFromFile(DEVICE, file.c_str(), nullptr, nullptr, D3DXSHADER_DEBUG,
		nullptr, &shader, nullptr);
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

void Shader::Begin(int passIndex)
{
	shader->Begin(nullptr, 0);
	shader->BeginPass(passIndex);
}

void Shader::End()
{
	shader->EndPass();
	shader->End();
}

void Shader::SetInt(string param, int data)
{
	shader->SetInt(param.c_str(), data);
}

void Shader::SetFloat(string param, float data)
{
	shader->SetFloat(param.c_str(), data);
}

void Shader::SetArray(string param, void* data, int count)
{
	shader->SetFloatArray(param.c_str(), (float*)data, count);
}

void Shader::SetTexture(string param, LPDIRECT3DTEXTURE9 texture)
{
	shader->SetTexture(param.c_str(), texture);
}

void Shader::SetMatrix(string param, Matrix* matrix)
{
	shader->SetMatrix(param.c_str(), matrix);
}
