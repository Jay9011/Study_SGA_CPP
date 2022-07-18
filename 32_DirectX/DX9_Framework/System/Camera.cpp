#include "Framework.h"
#include "Camera.h"

Camera::Camera()
	: speed(200), target(nullptr), offset(WIN_CENTER_X, WIN_CENTER_Y)
{
}

Camera::~Camera()
{
}

void Camera::Update()
{
	if (target == nullptr)
		FreeMode();
	else
		TargetMode();

	UpdateWorld();

	DEVICE->SetTransform(D3DTS_VIEW, &world);
}

void Camera::FreeMode()
{
	if (KEYPRESS(VK_RBUTTON))
	{
		if (KEYPRESS('A'))
		{
			pos += V_RIGHT * speed * Time::Delta();
		}
		if (KEYPRESS('D'))
		{
			pos += V_LEFT * speed * Time::Delta();
		}
		if (KEYPRESS('W'))
		{
			pos += V_DOWN * speed * Time::Delta();
		}
		if (KEYPRESS('S'))
		{
			pos += V_UP * speed * Time::Delta();
		}
		
	}
}

void Camera::TargetMode()
{
	Vector2 destination = target->pos;

	destination = -(destination - offset);

	D3DXVec2Lerp(&this->pos, &this->pos, &destination, Time::Delta());
}
