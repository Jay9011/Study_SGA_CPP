#pragma once

#define BACKGROUND	3

class Landscape
{
public:
	Landscape();
	~Landscape();

	void Update();
	void Render();

private:
	vector<Object*> backgrounds;
	double bgSpeed;

};
