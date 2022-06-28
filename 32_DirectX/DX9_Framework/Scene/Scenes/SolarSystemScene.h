#pragma once
class SolarSystemScene : public IScene
{
public:
	SolarSystemScene();
	~SolarSystemScene();

	// IScene��(��) ���� ��ӵ�
	virtual void Update() override;
	virtual void Render() override;

private:
	Planet* sun;
	Planet* earth;
	Planet* moon;


};
