#pragma once

class VertexScene : public Scene
{
public:
	VertexScene();
	~VertexScene();

	virtual void Update() override;
	virtual void Render() override;

private:
	//Vertex(정점) : 3D 공간 상의 한 점
	struct Vertex
	{
		D3DXVECTOR4 position;
		D3DCOLOR    color;
	};

	Vertex vertices[6];

	DWORD fvf;
};
