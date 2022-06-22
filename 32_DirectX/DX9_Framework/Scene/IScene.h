#pragma once

class IScene
{
public:
	virtual void Update() = 0;
	virtual void Render() = 0;
};