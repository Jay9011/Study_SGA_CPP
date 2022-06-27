#pragma once
/*
*   Direct 3D ������ �� Device �������̽� ����
*/
class Device
{
public:
	Device();
	~Device();

    LPDIRECT3DDEVICE9 GetDevice() { return device; }

    void SetProjection();

private:
    
    // �ý��� �ϵ���� ��ġ�� ������ �޾ƿ��� ��ü
    LPDIRECT3D9 d3d;

    // 3D �׷����� ����� �׸��µ� �ʿ��� ������ �޾ƿ��� ��ü
    LPDIRECT3DDEVICE9 device;

    D3DXMATRIX projection;
};
