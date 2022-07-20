#include "Framework.h"
#include "Device.h"

Device* Device::instance = nullptr;

Device::Device()
{
	d3d = Direct3DCreate9(D3D_SDK_VERSION);

	//device 객체의 속성을 결정하는 구조체
    D3DPRESENT_PARAMETERS param = {};

    param.Windowed               = true; //창모드 = true, 전체화면 = false
    param.SwapEffect             = D3DSWAPEFFECT_DISCARD;
    param.EnableAutoDepthStencil = true;
    param.AutoDepthStencilFormat = D3DFMT_D16;

    //V-Sync
    param.PresentationInterval   = D3DPRESENT_INTERVAL_IMMEDIATE;

    d3d->CreateDevice
    (
        D3DADAPTER_DEFAULT,
        D3DDEVTYPE_HAL,
        hWnd,
        D3DCREATE_HARDWARE_VERTEXPROCESSING,
        &param,
        &device
    );

    SetProjection();
}

Device::~Device()
{
    d3d->Release();
}

void Device::SetProjection()
{
    D3DXMatrixOrthoOffCenterLH
    (
        &projection,
        0.0f, WIN_WIDTH,
        WIN_HEIGHT, 0.0f,
        -1.0f, 1.0f
    );

    //device->SetTransform(D3DTS_PROJECTION, &projection);

    device->SetRenderState(D3DRS_LIGHTING, false);
}
