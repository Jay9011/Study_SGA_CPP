#pragma once
class WVPScene : public IScene
{
public:
	WVPScene();
	~WVPScene();

	// IScene��(��) ���� ��ӵ�
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

		static const DWORD fvf = D3DFVF_XYZRHW | D3DFVF_DIFFUSE;	// static const �� �ʱ�ȭ�ϸ� h���� �ʱ�ȭ�� �� ������ ���� ������ �� ����.
	};

	vector<Vertex> vertices;
	D3DXMATRIX projection;
};
