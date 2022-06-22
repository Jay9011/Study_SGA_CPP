#pragma once

class VertexScene : public IScene
{
public:
	VertexScene();
	~VertexScene();

	// IScene을(를) 통해 상속됨
	virtual void Update() override;
	virtual void Render() override;


private:
	// Vertex (정점) : 3D 공간 상의 한 점.
	struct Vertex
	{
		D3DXVECTOR4 position;
		D3DCOLOR    color;
	};
	Vertex vertices[6];
	// Vector4 (x, y, z, w) -> (x * 1/w, y * 1/w, z * 1/w, w * 1/w = 1)

	// Flexible Vertex Format
	// XYZRHW = 2차원 좌표, RHW (Reciprocal Homogeneous W) = 1/w
	// XYZ    = 3차원 좌표
	DWORD fvf;
};

