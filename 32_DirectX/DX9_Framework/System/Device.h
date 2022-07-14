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

	//시스템 하드웨어 장치의 정보를 받아오는 객체
	LPDIRECT3D9 d3d;

	//3D 그래픽을 만들고 그리는데 필요한 객체
	LPDIRECT3DDEVICE9 device;

	Matrix projection;
};
