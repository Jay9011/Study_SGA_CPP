#pragma once

/*
Frame per Second (FPS)

�ʴ� ������: 1�ʿ� �� ���� ȭ���� ���°�

�ֻ���: �� ����Ͱ� ǥ���� �� �ִ� �ִ� ������

���� ����ȭ: ������� �ֻ����� �� ��ǻ�� �������� �ִ�ġ�� ��ġ��Ű�� ���


Update: �� �����Ӹ��� ���ŵǴ� �������� ������Ʈ�ϴ� �Լ�

Render: �� �����Ӹ��� �׸��� ������Ʈ�ϴ� �Լ�

*/

class Scene
{
public:
	virtual ~Scene() = default;

	virtual void Update() = 0;
	virtual void Render(HDC hdc) = 0;
};