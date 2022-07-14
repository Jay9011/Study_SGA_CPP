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

	static const DWORD fvf = D3DFVF_XYZ | D3DFVF_DIFFUSE;
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
		this->uv       = { u, v } ;
	}

	Vector3 position;
	Vector2	uv;

	static const DWORD fvf = D3DFVF_XYZ | D3DFVF_TEX1;
};

class Transform
{
public:
	Transform();
	virtual ~Transform();

	virtual void UpdateWorld();

	void SetWorld();

	void SetParent(Transform* parent) { this->parent = parent; }

	Matrix* GetWorld()       { return &world; }
	Matrix* GetScale()       { return &S; }
	Matrix* GetRotation()    { return &R; }
	Matrix* GetTranslation() { return &T; }

public:
	Vector2 pos;
	Vector2 scale;
	float   angle;

protected:
	Matrix world;

	Matrix S, R, T;

	Vector2 pivot;

	Transform* parent;
};
