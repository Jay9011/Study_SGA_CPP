#include "Framework.h"
#include "Camera.h"

Camera* Camera::instance = nullptr;

Camera::Camera()
	: pos({0, 0})
	, speed(10)
{
}

Camera::~Camera()
{
}

void Camera::Create()
{
	if (instance == nullptr)
		instance = new Camera;
}

void Camera::Delete()
{
	if (instance != nullptr)
		delete instance;

	instance = nullptr;
}

Camera* Camera::Get()
{
	return instance;
}

void Camera::Update()
{
}
