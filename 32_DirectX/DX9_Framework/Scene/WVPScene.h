#pragma once

class WVPScene : public Scene
{
public:
	WVPScene();
	~WVPScene();

	virtual void Update() override;
	virtual void Render() override;

private:
	struct Vertex
	{
		Vertex(float x, float y, D3DCOLOR color)
		{
			this->position = { x, y, 0 };
			this->color    = color;
		}

		D3DXVECTOR3 position;
		D3DCOLOR	color;

		static const DWORD fvf = D3DFVF_XYZ | D3DFVF_DIFFUSE;
	};

	vector<Vertex> vertices;

	D3DXMATRIX projection;
	D3DXMATRIX world;
	D3DXMATRIX view;

	D3DXMATRIX S, R, T;

	D3DXVECTOR2 pos;
	D3DXVECTOR2 scale;
	double      angle;

	D3DXVECTOR2 pivot;

	D3DXVECTOR2 up;
	D3DXVECTOR2 right;
};
