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
    *   Back-face culling : 그래픽 개체의 다각형이 보이는지 여부를 결정. 다각형의 포인트가 화면에 투영 될 때 시계 방향 또는 시계 반대 방향으로 보이는지 여부를 테스트하는 그래픽 파이프 라인의 한 단계.
    */

}
