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
		Vertex(float x, float y, D3DCOLOR color)
		{
			this->position = { x, y, 0 };
			this->color    = color;
		}

		D3DXVECTOR3 position;
		D3DCOLOR	color;

		static const DWORD fvf = D3DFVF_XYZ | D3DFVF_DIFFUSE;	// static const �� �ʱ�ȭ�ϸ� h���� �ʱ�ȭ�� �� ������ ���� ������ �� ����.
	};

	vector<Vertex> vertices;

	D3DXMATRIX projection;
};
