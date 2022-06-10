#include "Framework.h"
#include "CalculatorScene.h"

CalculatorScene::CalculatorScene()
{
	for (size_t i = 0; i < 10; i++)
	{
		Texture* tmp = TextureManager::Get()->AddTexture("num" + to_string(i), L"textures/Cal/Num_0" + to_wstring(i) + L".png");
		Texture* tmpO = TextureManager::Get()->AddTexture("num" + to_string(i) + "_O", L"textures/Cal/Num_0" + to_wstring(i) + L"_O.png");

		if (i > 0)
		{
			padButtons.emplace("num" + to_string(i), new Button(tmp, tmp, tmpO, { tmp->GetFrameSize().x * ((i - 1) % 3) + tmp->GetFrameSize().x * .5, (WIN_HEIGHT - tmp->GetFrameSize().y) - (tmp->GetFrameSize().y * ((i - 1) / 3)) - (tmp->GetFrameSize().y * .5) }));
		}
		else
		{
			padButtons.emplace("num" + to_string(i), new Button(tmp, tmp, tmpO, { 150 + tmp->GetFrameSize().x * .5, WIN_HEIGHT - tmp->GetFrameSize().y * .5 }));
		}
	}

	Texture* add = TextureManager::Get()->AddTexture("add", L"textures/Cal/Add.png");
	Texture* addO = TextureManager::Get()->AddTexture("add_O", L"textures/Cal/Add_O.png");
	padButtons.emplace("add", new Button(add, add, addO, { add->GetFrameSize().y * 3 + add->GetFrameSize().y * .5, WIN_HEIGHT - (add->GetFrameSize().y * .5) - (add->GetFrameSize().y * 0) }));
	Texture* sub = TextureManager::Get()->AddTexture("sub", L"textures/Cal/Sub.png");
	Texture* subO = TextureManager::Get()->AddTexture("sub_O", L"textures/Cal/Sub_O.png");
	padButtons.emplace("sub", new Button(sub, sub, subO, { sub->GetFrameSize().y * 3 + sub->GetFrameSize().y * .5, WIN_HEIGHT - (sub->GetFrameSize().y * .5) - (sub->GetFrameSize().y * 1) }));
	Texture* mul = TextureManager::Get()->AddTexture("mul", L"textures/Cal/Mul.png");
	Texture* mulO = TextureManager::Get()->AddTexture("mul_O", L"textures/Cal/Mul_O.png");
	padButtons.emplace("mul", new Button(mul, mul, mulO, { mul->GetFrameSize().y * 3 + mul->GetFrameSize().y * .5, WIN_HEIGHT - (mul->GetFrameSize().y * .5) - (mul->GetFrameSize().y * 2) }));
	Texture* div = TextureManager::Get()->AddTexture("div", L"textures/Cal/Div.png");
	Texture* divO = TextureManager::Get()->AddTexture("div_O", L"textures/Cal/Div_O.png");
	padButtons.emplace("div", new Button(div, div, divO, { div->GetFrameSize().y * 3 + div->GetFrameSize().y * .5, WIN_HEIGHT - (div->GetFrameSize().y * .5) - (div->GetFrameSize().y * 3) }));
	Texture* clear = TextureManager::Get()->AddTexture("clear", L"textures/Cal/Clear.png");
	Texture* clearO = TextureManager::Get()->AddTexture("clear_O", L"textures/Cal/Clear_O.png");
	padButtons.emplace("clear", new Button(clear, clear, clearO, { clear->GetFrameSize().y * .5, WIN_HEIGHT - clear->GetFrameSize().y * .5 }));
	Texture* end = TextureManager::Get()->AddTexture("end", L"textures/Cal/End.png");
	Texture* endO = TextureManager::Get()->AddTexture("end_O", L"textures/Cal/End_O.png");
	padButtons.emplace("end", new Button(end, end, endO, { end->GetFrameSize().y * 2 + end->GetFrameSize().y * .5, WIN_HEIGHT - (end->GetFrameSize().y * .5) - (end->GetFrameSize().y * 0) }));
}

CalculatorScene::~CalculatorScene()
{
	for (pair<string, Button*> button : padButtons)
	{
		delete button.second;
	}
	padButtons.clear();
}

void CalculatorScene::Update()
{
	for (pair<string, Button*> button : padButtons)
		button.second->Update();
}

void CalculatorScene::Render(HDC hdc)
{
	for (pair<string, Button*> button : padButtons)
		button.second->Render();
}
