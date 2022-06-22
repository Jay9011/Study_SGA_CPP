#pragma once

class VertexScene : public IScene
{
public:
	VertexScene();
	~VertexScene();

	// IScene��(��) ���� ��ӵ�
	virtual void Update() override;
	virtual void Render() override;


private:
	// Vertex (����) : 3D ���� ���� �� ��.
	struct Vertex
	{
		D3DXVECTOR4 position;
		D3DCOLOR    color;
	};
	Vertex vertices[6];
	// Vector4 (x, y, z, w) -> (x * 1/w, y * 1/w, z * 1/w, w * 1/w = 1)

	// Flexible Vertex Format
	// XYZRHW = 2���� ��ǥ, RHW (Reciprocal Homogeneous W) = 1/w
	// XYZ    = 3���� ��ǥ
	DWORD fvf;
};

