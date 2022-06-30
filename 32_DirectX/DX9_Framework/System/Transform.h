#pragma once

struct VertexColor
{
	VertexColor(float x, float y, D3DCOLOR color)
	{
		this->position = { x, y, 0 };
		this->color = color;
	}

	D3DXVECTOR3 position;
	D3DCOLOR	color;

	static const DWORD fvf = D3DFVF_XYZ | D3DFVF_DIFFUSE;	// static const �� �ʱ�ȭ�ϸ� h���� �ʱ�ȭ�� �� ������ ���� ������ �� ����.
};

struct VertexTexture
{
	VertexTexture()
	{
		this->position = { 0, 0, 0 };
		this->uv       = { 0, 0 };
	}
	VertexTexture(float x, float y, float u, float v)
	{
		this->position = { x, y, 0 };
		this->uv       = { u, v };
	}

	D3DXVECTOR3 position;
	D3DXVECTOR2 uv;

	static const DWORD fvf = D3DFVF_XYZ | D3DFVF_TEX1;
};

class Transform
{
public:
	Transform();
	virtual ~Transform();

	virtual void UpdateWorld();
	
	void  SetWorld();
	const D3DMATRIX* GetWorld()       const { return &world; }
	const D3DMATRIX* GetScale()       const { return &S; }
	const D3DMATRIX* GetRotation()    const { return &R; }
	const D3DMATRIX* GetTranslation() const { return &T; }
	void SetParent(Transform* parent) { this->parent = parent; };

public:
	D3DXVECTOR2 pos;
	D3DXVECTOR2 scale;
	float       angle;

protected:
	D3DXMATRIX world;

	D3DXMATRIX S;	// scaling
	D3DXMATRIX R;	// rotation
	D3DXMATRIX T;	// translation

	D3DXVECTOR2 pivot;

	Transform* parent;

};