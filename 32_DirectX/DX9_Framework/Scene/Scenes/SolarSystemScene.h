#pragma once
class SolarSystemScene : public IScene
{
public:
	SolarSystemScene();
	~SolarSystemScene();

	// IScene을(를) 통해 상속됨
	virtual void Update() override;
	virtual void Render() override;

private:
	Planet* sun;
	Planet* earth;
	Planet* moon;


};
