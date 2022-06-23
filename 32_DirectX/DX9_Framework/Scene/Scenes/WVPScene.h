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
		Vertex(float _x, float _y, D3DCOLOR _color)
		{
			position = { _x, _y, 0, 1 };
			color    = _color;
		}

		D3DXVECTOR4 position;
		D3DCOLOR	color;

		static const DWORD fvf = D3DFVF_XYZRHW | D3DFVF_DIFFUSE;	// static const 로 초기화하면 h에서 초기화할 수 있지만 이후 변경할 수 없다.
	};

	vector<Vertex> vertices;
	D3DXMATRIX projection;
};
