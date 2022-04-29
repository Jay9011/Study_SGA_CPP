#include "Framework.h"
#include "AKUI.h"

AKUI::AKUI()
	: border(3)
	, score(0)
	, oldBrush(nullptr)
	, oldPen(nullptr)
{
	scoreBox = new Rect(10, border, WIN_WIDTH - 10.0, 50);
	stageBox = new Rect(
		10,
		scoreBox->Bottom() + border,
		WIN_WIDTH  - 10.0,
		WIN_HEIGHT - (double)border
	);

	whitePen = CreatePen(PS_SOLID, border, COLOR_WHITE);
	blackPen = CreatePen(PS_SOLID, border, COLOR_BLACK);
	redPen   = CreatePen(PS_SOLID, border, COLOR_RED);
	whiteBrush = CreateSolidBrush(COLOR_WHITE);
	blackBrush = CreateSolidBrush(COLOR_BLACK);
}

AKUI::~AKUI()
{
	delete scoreBox;
	delete stageBox;

	DeleteObject(blackPen);
	DeleteObject(whitePen);
	DeleteObject(redPen);
	DeleteObject(whiteBrush);
	DeleteObject(blackBrush);
}

void AKUI::Update()
{
}

void AKUI::Render(HDC hdc)
{
	oldPen = (HPEN)SelectObject(hdc, whitePen);
	scoreBox->Render(hdc);
	SelectObject(hdc, oldPen);

	wstring str = L"현재 점수 : ";
	str += to_wstring(score);
	TextOut(hdc
			, scoreBox->Left() + 10
			, (scoreBox->Bottom() - scoreBox->Top()) / 2
			, str.c_str()
			, str.length()
			);

	oldPen = (HPEN)SelectObject(hdc, blackPen);
	stageBox->Render(hdc);
	SelectObject(hdc, oldPen);
}

void AKUI::SetScore(int _addScore)
{
	score += _addScore;
}
