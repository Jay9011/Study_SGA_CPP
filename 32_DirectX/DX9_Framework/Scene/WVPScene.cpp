#include "Framework.h"
#include "WVPScene.h"

WVPScene::WVPScene()
	:pos(300, 300), scale(1, 1), pivot(100, 100), angle(0)
{
	vertices.push_back(Vertex(  0,   0, 0xFFFF0000));
	vertices.push_back(Vertex(200,   0, 0xFF00FF00));
	vertices.push_back(Vertex(  0, 200, 0xFF0000FF));

	vertices.push_back(Vertex(  0, 200, 0xFF0000FF));
	vertices.push_back(Vertex(200,   0, 0xFF00FF00));
	vertices.push_back(Vertex(200, 200, 0xFFFF00FF));

	D3DXMatrixOrthoOffCenterLH
	(
		&projection,
			  0.0f, WIN_WIDTH,
		WIN_HEIGHT,      0.0f,
			 -1.0f,      1.0f
	);

	DEVICE->SetTransform(D3DTS_PROJECTION, &projection);

	DEVICE->SetRenderState(D3DRS_LIGHTING, false);

	//World Matrix
	D3DXMatrixIdentity(&world);
	DEVICE->SetTransform(D3DTS_WORLD, &world);

	//View
	D3DXMatrixIdentity(&view);
	DEVICE->SetTransform(D3DTS_VIEW, &view);
}

WVPScene::~WVPScene()
{
}

void WVPScene::Update()
{
	if (KEYPRESS(VK_LEFT))
	{
		//world._41--;
		//pos.x--;
		pos -= right;
	}

	if (KEYPRESS(VK_RIGHT))
	{
		//world._41++;
		//pos.x++;
		pos += right;
	}

	if (KEYPRESS(VK_UP))
	{
		//world._42--;
		//pos.y--;
		pos -= up;
	}

	if (KEYPRESS(VK_DOWN))
	{
		//world._42++;
		//pos.y++;
		pos += up;
	}

	D3DXMatrixTranslation(&T, pos.x, pos.y, 0.0f);

	if (KEYPRESS('A'))
	{
		//world._11--;
		scale.x -= 0.01f;
	}

	if (KEYPRESS('S'))
	{
		scale.y += 0.01f;
	}

	if (KEYPRESS('D'))
	{
		scale.x += 0.01f;
	}

	if (KEYPRESS('W'))
	{
		scale.y -= 0.01f;
	}

	D3DXMatrixScaling(&S, scale.x, scale.y, 1.0f);

	if (KEYPRESS('K'))
	{
		angle += 0.01f;
	}

	if (KEYPRESS('I'))
	{
		angle -= 0.01f;
	}

	/*world._11 =  cos(angle);
	world._12 =  sin(angle);
	world._21 = -sin(angle);
	world._22 =  cos(angle);*/

	D3DXMatrixRotationZ(&R, angle);

	//world = S * R * T;

	D3DXMATRIX P, IP;

	D3DXMatrixTranslation(&P, pivot.x, pivot.y, 0.0f);
	D3DXMatrixInverse(&IP, nullptr, &P);

	world = IP * S * R * T * P;

	//View
	if (KEYPRESS('F'))
		view._41++;
	if (KEYPRESS('H'))
		view._41--;
	if (KEYPRESS('T'))
		view._42++;
	if (KEYPRESS('G'))
		view._42--;

	DEVICE->SetTransform(D3DTS_VIEW, &view);

	//���⺤��
	right.x = world._11;
	right.y = world._12;

	up.x = world._21;
	up.y = world._22;
}

void WVPScene::Render()
{
	DEVICE->SetFVF(Vertex::fvf);
	DEVICE->SetTransform(D3DTS_WORLD, &world);
	DEVICE->DrawPrimitiveUP(D3DPT_TRIANGLELIST, 2, vertices.data(), sizeof(Vertex));
}

