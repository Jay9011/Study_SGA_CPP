#include "Framework.h"
#include "Camera.h"

Camera* Camera::instance = nullptr;

Camera::Camera()
	: speed(100)
	, target(nullptr)
	, pos{ 0, 0 }
	, offset(WIN_CENTER_X, WIN_CENTER_Y)
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
	if (target != nullptr)
	{
		this->pos = target->GetRect()->Pos() - offset;
	}
	else
	{
		if (KEY_PRESS('A'))
		{
			this->pos += V_LEFT * speed * Time::Delta();
		}
		else if (KEY_PRESS('D'))
		{
			this->pos += V_RIGHT * speed * Time::Delta();
		}

		if (KEY_PRESS('W'))
		{
			this->pos += V_UP * speed * Time::Delta();
		}
		else if (KEY_PRESS('S'))
		{
			this->pos += V_DOWN * speed * Time::Delta();
		}
	}
}
