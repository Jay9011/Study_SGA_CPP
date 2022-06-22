#include "Framework.h"
#include "VertexScene.h"

VertexScene::VertexScene()
{
    vertices[0].position = { 100, 100, 0, 1 };
    vertices[0].color = 0xFFFF0000;
    vertices[1].position = { 200, 100, 0, 1 };
    vertices[1].color = 0xFF00FF00;
    vertices[2].position = { 100, 200, 0, 1 };
    vertices[2].color = 0xFF0000FF;
    vertices[3].position = { 100, 200, 0, 1 };
    vertices[3].color = 0xFF00FF00;
    vertices[4].position = { 200, 100, 0, 1 };
    vertices[4].color = 0xFF0000FF;
    vertices[5].position = { 200, 200, 0, 1 };
    vertices[5].color = 0xFFFFFFFF;
    
    fvf = D3DFVF_XYZRHW | D3DFVF_DIFFUSE;
}

VertexScene::~VertexScene()
{
}

void VertexScene::Update()
{
}

void VertexScene::Render()
{

    DEVICE->SetFVF(fvf);
    DEVICE->DrawPrimitiveUP(D3DPT_TRIANGLELIST, 2, &vertices, sizeof(Vertex));

    /*
    *   Polygon
    *
    *   Back-face culling : �׷��� ��ü�� �ٰ����� ���̴��� ���θ� ����. �ٰ����� ����Ʈ�� ȭ�鿡 ���� �� �� �ð� ���� �Ǵ� �ð� �ݴ� �������� ���̴��� ���θ� �׽�Ʈ�ϴ� �׷��� ������ ������ �� �ܰ�.
    */

}
