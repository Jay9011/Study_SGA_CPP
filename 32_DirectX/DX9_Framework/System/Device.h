#pragma once

class Device
{
	Device();
	~Device();
public:
	static void Create()
	{
		if (instance == nullptr)
			instance = new Device;
	}

	static void Delete() { delete instance; }

	static Device* Get() { return instance; }

	LPDIRECT3DDEVICE9 GetDevice() { return device; }

	void SetProjection();

private:
	static Device* instance;

	//�ý��� �ϵ���� ��ġ�� ������ �޾ƿ��� ��ü
	LPDIRECT3D9 d3d;

	//3D �׷����� ����� �׸��µ� �ʿ��� ��ü
	LPDIRECT3DDEVICE9 device;

	Matrix projection;
};
