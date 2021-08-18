#pragma once
#include "gameNode.h"

#define PI 3.14156f

class playGround : public gameNode
{
private:
	//PI == 3.14 == 180��
	//1���� == ȣ�� ���̶� �������� ��ġ�ϸ� 1���� 
	//          57.3�� �����̴�

	float _radian;
	float _degree;
	
public:
	playGround();
	~playGround();

	virtual HRESULT init();			//�ʱ�ȭ �Լ�
	virtual void release();			//�޸� ���� �Խ�
	virtual void update();			//�����ϴ� �Լ�
	virtual void render(HDC hdc);	//�׸��� �Լ�

	
};

