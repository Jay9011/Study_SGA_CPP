#pragma once
class WVPScene : public IScene
{
public:
	WVPScene();
	~WVPScene();

	// IScene을(를) 통해 상속됨
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

		static const DWORD fvf = D3DFVF_XYZ | D3DFVF_DIFFUSE;	// static const 로 초기화하면 h에서 초기화할 수 있지만 이후 변경할 수 없다.
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
