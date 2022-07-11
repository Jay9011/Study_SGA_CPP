#pragma once
/*
*   Direct 3D ������ �� Device �������̽� ����
*/
class Device
{
private:
	Device();
	~Device();
    static Device* instance;
public:
    static void Create() { if (instance == nullptr) instance = new Device; }
    static void Delete() { delete instance; }
    static Device* Get() { return instance; }

public:
    LPDIRECT3DDEVICE9 GetDevice() { return device; }

    void SetProjection();

private:
    
    // �ý��� �ϵ���� ��ġ�� ������ �޾ƿ��� ��ü
    LPDIRECT3D9 d3d;

    // 3D �׷����� ����� �׸��µ� �ʿ��� ������ �޾ƿ��� ��ü
    LPDIRECT3DDEVICE9 device;

    D3DXMATRIX projection;
};
