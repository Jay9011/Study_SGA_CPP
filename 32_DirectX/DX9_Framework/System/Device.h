#pragma once
/*
*   Direct 3D 가져온 후 Device 인터페이스 생성
*/
class Device
{
public:
	Device();
	~Device();

    LPDIRECT3DDEVICE9 GetDevice() { return device; }

    void SetProjection();

private:
    
    // 시스템 하드웨어 장치의 정보를 받아오는 객체
    LPDIRECT3D9 d3d;

    // 3D 그래픽을 만들고 그리는데 필요한 정보를 받아오는 객체
    LPDIRECT3DDEVICE9 device;

    D3DXMATRIX projection;
};
