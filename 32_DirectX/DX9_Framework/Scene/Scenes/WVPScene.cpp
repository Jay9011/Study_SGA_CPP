#include "Framework.h"
#include "WVPScene.h"

WVPScene::WVPScene()
{
	vertices.push_back(Vertex(  0,   0, 0xFFFF0000));
	vertices.push_back(Vertex(100,   0, 0xFF00FF00));
	vertices.push_back(Vertex(  0, 100, 0xFF0000FF));

	D3DXMatrixOrthoOffCenterLH
	(
		&projection,
		       0.f, WIN_WIDTH,
		WIN_HEIGHT,       0.f,
		      -1.f,       1.f
	);

	DEVICE->SetTransform(D3DTS_PROJECTION, &projection);
	DEVICE->SetRenderState(D3DRS_LIGHTING, false);
}

WVPScene::~WVPScene()
{
}

void WVPScene::Update()
{
}

void WVPScene::Render()
{
	DEVICE->SetFVF(Vertex::fvf);
	DEVICE->DrawPrimitiveUP(D3DPT_TRIANGLELIST, 1, &vertices[0], sizeof(Vertex));
}
