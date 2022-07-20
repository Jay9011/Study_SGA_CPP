#pragma once
class Object : public Transform
{
public:
	Object(wstring file, Vector2 size = Vector2(0, 0));
	~Object();

	void Update();
	void Render();

	Texture* GetTexture() { return texture; }

	void    SetShader(Shader* shader) { this->shader = shader; }
	Shader* GetShader()               { return shader; }

private:
	Shader* shader;
	Texture* texture;

};

