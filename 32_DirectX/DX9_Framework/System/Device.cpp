#include "Framework.h"
#include "Device.h"

Device::Device()
{
	d3d = Direct3DCreate9(D3D_SDK_VERSION);

    // Device ��ü�� �Ӽ��� �����ϴ� ����ü
    D3DPRESENT_PARAMETERS param{};

    param.Windowed = true;  // â��� ����( â��� : true, ��üȭ�� : false )
    param.SwapEffect = D3DSWAPEFFECT_DISCARD;
    param.EnableAutoDepthStencil = true;
    param.AutoDepthStencilFormat = D3DFMT_D16;

    // V-Sync
    param.PresentationInterval = D3DPRESENT_INTERVAL_IMMEDIATE;

    // �޾ƿ� �ϵ���� ������ �ʱ�ȭ��Ų �Ӽ��� �̿��ؼ� Device ��ü�� �����.
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
