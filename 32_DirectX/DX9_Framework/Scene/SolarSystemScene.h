#pragma once

class SolarSystemScene : public Scene
{
public:
	SolarSystemScene();
	~SolarSystemScene();

	virtual void Update() override;
	virtual void Render() override;

private:
	Planet* sun;
	Planet* earth;
	Planet* moon;
};
