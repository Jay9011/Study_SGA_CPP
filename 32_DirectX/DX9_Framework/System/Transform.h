#pragma once

struct Vertex
{
	Vertex(float x, float y, D3DCOLOR color)
	{
		this->position = { x, y, 0 };
		this->color = color;
	}

	D3DXVECTOR3 position;
	D3DCOLOR	color;

	static const DWORD fvf = D3DFVF_XYZ | D3DFVF_DIFFUSE;	// static const �� �ʱ�ȭ�ϸ� h���� �ʱ�ȭ�� �� ������ ���� ������ �� ����.
};

class Transform
{
public:
	Transform();
	virtual ~Transform();

	virtual void UpdateWorld();
	
	void SetWorld();
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
