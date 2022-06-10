#include "Framework.h"
#include "CalculatorScene.h"

CalculatorScene::CalculatorScene()
	: oper(OPERATOR::NONE)
	, tmpOper(OPERATOR::NONE)
	, beforeRst(0)
	, rstNum(0)
	, tmpNum(0)
{
	// 버튼 세팅
	ButtonSetting();

	// Texture 세팅
	numbersTexture = TextureManager::Get()->AddTexture("Numbers", L"textures/Cal/Numbers.png");
	numbers = new RECT[(int)NUMBER::END];

	opersTexture = TextureManager::Get()->AddTexture("Opers", L"textures/Cal/Opers.png");
	opers = new RECT[(int)OPERATOR::CLEAR];
	
	LoadXML();
}

CalculatorScene::~CalculatorScene()
{
	for (pair<string, Button*> button : padButtons)
	{
		delete button.second;
	}
	padButtons.clear();

	delete[] numbers;
	delete[] opers;
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

	// 숫자 표기
	int digit = 0;			// 자릿수
	int rest  = 0;			// 표시할 숫자
	int quot  = showingNum;	// 몫

	while (true)
	{
		rest = quot % 10;
		RenderNumber(digit, (NUMBER)rest);
		
		++digit;
		quot /= 10;
		if (quot == 0)
			break;
	}

	// 상위 숫자 표기
	RenderResultAndOperator();
}

void CalculatorScene::OperatorChange(OPERATOR _oper)
{
	if (OPERATOR::CLEAR == _oper)
	{
		oper = OPERATOR::NONE;
		tmpOper = OPERATOR::NONE;
		rstNum = 0;
		tmpNum = 0;
		SetShowingNum(rstNum);
		return;
	}

	beforeRst = rstNum;

	// 결과 계산
	switch (oper)
	{
	case OPERATOR::NONE:
		rstNum = tmpNum;
		break;
	case OPERATOR::ADD:
		rstNum += tmpNum;
		break;
	case OPERATOR::SUB:
		rstNum -= tmpNum;
		break;
	case OPERATOR::MUL:
		rstNum *= tmpNum;
		break;
	case OPERATOR::DIV:
		rstNum /= tmpNum;
		break;
	}

	SetShowingNum(rstNum);

	if (OPERATOR::RESULT == _oper)
	{
		tmpOper = _oper;
		return;
	}

	// 다음 Operator 저장 후 임시 숫자 초기화
	tmpNum = 0;
	oper = _oper;
	tmpOper = OPERATOR::NONE;
}

void CalculatorScene::AccNumber(int _num)
{
	if (OPERATOR::RESULT == tmpOper)
	{
		tmpNum = _num;
		tmpOper = OPERATOR::NONE;
	}
	else
	{
		tmpNum *= 10;
		tmpNum += _num;
	}

	SetShowingNum(tmpNum);
}

void CalculatorScene::RenderNumber(UINT _digit, NUMBER _num)
{
	Rect rect = Rect({ (WIN_WIDTH - 50) - (double)(30 * _digit), 100 }, { 30, 50 });
	numbersTexture->Render(&rect, numbers[(int)_num]);
}

void CalculatorScene::RenderResultAndOperator()
{
	int	   left  = 0;
	double width = 10;
	double posX  = (WIN_WIDTH - 50);
	Rect rect = Rect({ posX - width, 50 }, { width, 15 });
	
	int rest = 0;		// 표시할 숫자
	int quot = rstNum;	// 몫

	// 연산자 표기
	if (OPERATOR::RESULT == tmpOper)
	{
		rect.Pos().x -= width;
		opersTexture->Render(&rect, opers[(int)tmpOper]);
		rect.Pos().x -= width;
		numbersTexture->Render(&rect, numbers[tmpNum]);
		quot = beforeRst;
	}
	rect.Pos().x -= width;
	opersTexture->Render(&rect, opers[(int)oper]);

	// 숫자 표기
	while (true)
	{
		rest = quot % 10;

		rect.Pos().x -= width;
		numbersTexture->Render(&rect, numbers[rest]);

		quot /= 10;
		if (quot == 0)
			break;
	}
}

void CalculatorScene::LoadXML()
{
	XmlDocument* document = new XmlDocument;
	document->LoadFile("textures/Cal/Numbers.xml");
	XmlElement* atlas  = document->FirstChildElement();
	XmlElement* sprite =    atlas->FirstChildElement();

	for(int i = 0; i < (int)NUMBER::END; i++)
	{
		numbers[i].left   = sprite->IntAttribute("x");
		numbers[i].top    = sprite->IntAttribute("y");
		numbers[i].right  = sprite->IntAttribute("w");
		numbers[i].bottom = sprite->IntAttribute("h");

		sprite = sprite->NextSiblingElement();

		if (sprite == nullptr)
			break;
	}

	document->Clear();
	
	document->LoadFile("textures/Cal/Opers.xml");
	atlas = document->FirstChildElement();
	sprite = atlas->FirstChildElement();

	for (int i = 0; i < (int)OPERATOR::CLEAR; i++)
	{
		opers[i].left = sprite->IntAttribute("x");
		opers[i].top = sprite->IntAttribute("y");
		opers[i].right = sprite->IntAttribute("w");
		opers[i].bottom = sprite->IntAttribute("h");

		sprite = sprite->NextSiblingElement();

		if (sprite == nullptr)
			break;
	}
	
	delete document;
}

void CalculatorScene::ButtonSetting()
{
	Button* btn = nullptr;

	for (size_t i = 0; i < 10; i++)
	{
		Texture* tmp = TextureManager::Get()->AddTexture("num" + to_string(i), L"textures/Cal/Num_0" + to_wstring(i) + L".png");
		Texture* tmpO = TextureManager::Get()->AddTexture("num" + to_string(i) + "_O", L"textures/Cal/Num_0" + to_wstring(i) + L"_O.png");

		if (i > 0)
		{	// 1부터 9까지
			btn = new Button(tmp, tmp, tmpO, { tmp->GetFrameSize().x * ((i - 1) % 3) + tmp->GetFrameSize().x * .5, (WIN_HEIGHT - tmp->GetFrameSize().y) - (tmp->GetFrameSize().y * ((i - 1) / 3)) - (tmp->GetFrameSize().y * .5) });
			btn->SetEvent(bind(&CalculatorScene::AccNumber, this, i));
			padButtons.emplace("num" + to_string(i), btn);
		}
		else
		{	// 0인 경우
			btn = new Button(tmp, tmp, tmpO, { 150 + tmp->GetFrameSize().x * .5, WIN_HEIGHT - tmp->GetFrameSize().y * .5 });
			btn->SetEvent(bind(&CalculatorScene::AccNumber, this, i));
			padButtons.emplace("num" + to_string(i), btn);
		}
	}

	Texture* add = TextureManager::Get()->AddTexture("add", L"textures/Cal/Add.png");
	Texture* addO = TextureManager::Get()->AddTexture("add_O", L"textures/Cal/Add_O.png");
	btn = new Button(add, add, addO, { add->GetFrameSize().y * 3 + add->GetFrameSize().y * .5, WIN_HEIGHT - (add->GetFrameSize().y * .5) - (add->GetFrameSize().y * 0) });
	btn->SetEvent(bind(&CalculatorScene::OperatorChange, this, OPERATOR::ADD));
	padButtons.emplace("add", btn);
	
	Texture* sub = TextureManager::Get()->AddTexture("sub", L"textures/Cal/Sub.png");
	Texture* subO = TextureManager::Get()->AddTexture("sub_O", L"textures/Cal/Sub_O.png");
	btn = new Button(sub, sub, subO, { sub->GetFrameSize().y * 3 + sub->GetFrameSize().y * .5, WIN_HEIGHT - (sub->GetFrameSize().y * .5) - (sub->GetFrameSize().y * 1) });
	btn->SetEvent(bind(&CalculatorScene::OperatorChange, this, OPERATOR::SUB));
	padButtons.emplace("sub", btn);
	
	Texture* mul = TextureManager::Get()->AddTexture("mul", L"textures/Cal/Mul.png");
	Texture* mulO = TextureManager::Get()->AddTexture("mul_O", L"textures/Cal/Mul_O.png");
	btn = new Button(mul, mul, mulO, { mul->GetFrameSize().y * 3 + mul->GetFrameSize().y * .5, WIN_HEIGHT - (mul->GetFrameSize().y * .5) - (mul->GetFrameSize().y * 2) });
	btn->SetEvent(bind(&CalculatorScene::OperatorChange, this, OPERATOR::MUL));
	padButtons.emplace("mul", btn);
	
	Texture* div = TextureManager::Get()->AddTexture("div", L"textures/Cal/Div.png");
	Texture* divO = TextureManager::Get()->AddTexture("div_O", L"textures/Cal/Div_O.png");
	btn = new Button(div, div, divO, { div->GetFrameSize().y * 3 + div->GetFrameSize().y * .5, WIN_HEIGHT - (div->GetFrameSize().y * .5) - (div->GetFrameSize().y * 3) });
	btn->SetEvent(bind(&CalculatorScene::OperatorChange, this, OPERATOR::DIV));
	padButtons.emplace("div", btn);
	
	Texture* clear = TextureManager::Get()->AddTexture("clear", L"textures/Cal/Clear.png");
	Texture* clearO = TextureManager::Get()->AddTexture("clear_O", L"textures/Cal/Clear_O.png");
	btn = new Button(clear, clear, clearO, { clear->GetFrameSize().y * .5, WIN_HEIGHT - clear->GetFrameSize().y * .5 });
	btn->SetEvent(bind(&CalculatorScene::OperatorChange, this, OPERATOR::CLEAR));
	padButtons.emplace("clear", btn);
	
	Texture* result = TextureManager::Get()->AddTexture("end", L"textures/Cal/Result.png");
	Texture* resultO = TextureManager::Get()->AddTexture("end_O", L"textures/Cal/Result_O.png");
	btn = new Button(result, result, resultO, { result->GetFrameSize().y * 2 + result->GetFrameSize().y * .5, WIN_HEIGHT - (result->GetFrameSize().y * .5) - (result->GetFrameSize().y * 0) });
	btn->SetEvent(bind(&CalculatorScene::OperatorChange, this, OPERATOR::RESULT));
	padButtons.emplace("end", btn);

}
