#pragma once

/*
Frame per Second (FPS)

초당 프레임: 1초에 몇 개의 화면을 띄우는가

주사율: 이 모니터가 표현할 수 있는 최대 프레임

수직 동기화: 모니터의 주사율과 내 컴퓨터 프레임의 최대치를 일치시키는 기법


Update: 매 프레임마다 갱신되는 정보들을 업데이트하는 함수

Render: 매 프레임마다 그림을 업데이트하는 함수

*/

class Scene
{
public:
	virtual ~Scene() = default;

	virtual void Update() = 0;
	virtual void Render(HDC hdc) = 0;
};