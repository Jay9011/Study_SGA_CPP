#include "Framework.h"
#include "PaintScene.h"

PaintScene::PaintScene()
	: type(PEN), color(RED), startPos({ 0, 0 }), endPos({ 0, 0 }), isClick(false), isPreview(false)
{
	hPen[RED]   = CreatePen(PS_SOLID, 3, COLOR_RED);
	hPen[GREEN] = CreatePen(PS_SOLID, 3, COLOR_GREEN);
	hPen[BLUE]  = CreatePen(PS_SOLID, 3, COLOR_BLUE);

	hBrush[RED]   = CreateSolidBrush(COLOR_RED);
	hBrush[GREEN] = CreateSolidBrush(COLOR_GREEN);
	hBrush[BLUE]  = CreateSolidBrush(COLOR_BLUE);

	hdc = GetDC(hWnd);
}

PaintScene::~PaintScene()
{
	for (UINT i = 0; i < 3; i++)
	{
		DeleteObject(  hPen[i]);
		DeleteObject(hBrush[i]);
	}

	ReleaseDC(hWnd, hdc);
}

void PaintScene::Update()
{
	SetType();

	if (GetAsyncKeyState(VK_LBUTTON))
	{
		if (!isClick)
		{
			isClick = true;
			LButtonDown();
		}
		else
		{
			if (type == PEN)
				DrawPen();
		}
	}
	else
	{
		if (isClick)
		{
			isClick = false;
			LButtonUp();
		}
	}
}

void PaintScene::Render(HDC hdc)
{
	for (size_t i = 0; i < objects.size(); ++i)
	{
		SelectObject(hdc,   hPen[objects[i].color]);
		SelectObject(hdc, hBrush[objects[i].color]);

		switch (objects[i].type)
		{
		case PaintScene::PEN:
		case PaintScene::LINE:
			MoveToEx(hdc, objects[i].startPos.x, objects[i].startPos.y, nullptr);
			LineTo	(hdc, objects[i].  endPos.x, objects[i].  endPos.y);
			break;
		case PaintScene::RECT:
			Rectangle(hdc, objects[i].startPos.x, objects[i].startPos.y, 
						   objects[i].  endPos.x, objects[i].  endPos.y);
			break;
		case PaintScene::ELLIPSE:
			Ellipse(hdc, objects[i].startPos.x, objects[i].startPos.y,
						 objects[i].  endPos.x, objects[i].  endPos.y);
			break;
		default:
			break;
		}
	}

	if (isPreview)
	{
		Preview();
	}
}

void PaintScene::SetType()
{
	if		(GetAsyncKeyState(VK_F1))
		type = PEN;
	else if (GetAsyncKeyState(VK_F2))
		type = LINE;
	else if (GetAsyncKeyState(VK_F3))
		type = RECT;
	else if (GetAsyncKeyState(VK_F4))
		type = ELLIPSE;

	if		(GetAsyncKeyState('1'))
		color = RED;
	else if (GetAsyncKeyState('2'))
		color = GREEN;
	else if (GetAsyncKeyState('3'))
		color = BLUE;
}

void PaintScene::LButtonDown()
{
	isPreview = true;

	startPos = mousePos;

	SelectObject(hdc,   hPen[color]);
	SelectObject(hdc, hBrush[color]);
}

void PaintScene::LButtonUp()
{
	isPreview = false;

	endPos = mousePos;

	Data data;
	data.startPos = startPos;
	data.endPos	  = endPos;
	data.color    = color;
	data.type	  = type;

	switch (type)
	{
	case PaintScene::LINE:
		objects.push_back(data);
		break;
	case PaintScene::RECT:
		objects.push_back(data);
		break;
	case PaintScene::ELLIPSE:
		objects.push_back(data);
		break;
	default:
		break;
	}
}

void PaintScene::DrawPen()
{
	endPos = mousePos;

	if (startPos.x == endPos.x && startPos.y == endPos.y)
		return;

	Data data;
	data.startPos = startPos;
	data.endPos   = endPos;
	data.color	  = color;
	data.type	  = type;

	objects.push_back(data);

	startPos = endPos;
}

void PaintScene::Preview()
{
	switch (type)
	{
	case PaintScene::LINE:
		MoveToEx(hdc, startPos.x, startPos.y, nullptr);
		LineTo	(hdc, mousePos.x, mousePos.y);
		break;
	case PaintScene::RECT:
		Rectangle(hdc, startPos.x, startPos.y, mousePos.x, mousePos.y);
		break;
	case PaintScene::ELLIPSE:
		Ellipse(hdc, startPos.x, startPos.y, mousePos.x, mousePos.y);
		break;
	default:
		break;
	}
}
