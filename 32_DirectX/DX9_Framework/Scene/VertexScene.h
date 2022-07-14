#pragma once

class VertexScene : public Scene
{
public:
	VertexScene();
	~VertexScene();

	virtual void Update() override;
	virtual void Render() override;

private:
	//Vertex(����) : 3D ���� ���� �� ��
	struct Vertex
	{
		D3DXVECTOR4 position;
		D3DCOLOR    color;
	};

	Vertex vertices[6];

	DWORD fvf;
};
