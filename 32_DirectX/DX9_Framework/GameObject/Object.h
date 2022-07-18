#pragma once
class Object : public Transform
{
public:
	Object(wstring file, Vector2 size = Vector2(0, 0));
	~Object();

	void Update();
	void Render();

	Texture* GetTexture() { return texture; }

private:
	Shader* shader;
	Texture* texture;

};

