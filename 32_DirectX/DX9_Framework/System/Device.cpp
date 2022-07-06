#include "Framework.h"
#include "Device.h"

Device::Device()
{
	d3d = Direct3DCreate9(D3D_SDK_VERSION);

    // Device 객체의 속성을 결정하는 구조체
    D3DPRESENT_PARAMETERS param{};

    param.Windowed = true;  // 창모드 결정( 창모드 : true, 전체화면 : false )
    param.SwapEffect = D3DSWAPEFFECT_DISCARD;
    param.EnableAutoDepthStencil = true;
    param.AutoDepthStencilFormat = D3DFMT_D16;

    // V-Sync
    param.PresentationInterval = D3DPRESENT_INTERVAL_IMMEDIATE;

    // 받아온 하드웨어 정보와 초기화시킨 속성을 이용해서 Device 객체를 만든다.
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
        0.f, WIN_WIDTH,
        WIN_HEIGHT, 0.f,
        -1.f, 1.f
    );

    device->SetTransform(D3DTS_PROJECTION, &projection);
    device->SetRenderState(D3DRS_LIGHTING, false);
}
