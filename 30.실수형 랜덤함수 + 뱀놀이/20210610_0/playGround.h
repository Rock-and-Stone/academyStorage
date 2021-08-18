#pragma once
#include "gameNode.h"

#define SNAKEBODY 100

struct tagSnake
{
	float x, y;
	float angle;
	float radius;
	float speed;
};


class playGround : public gameNode
{
private:
	tagSnake _snake[SNAKEBODY];
	
	
public:
	playGround();
	~playGround();

	virtual HRESULT init();			//�ʱ�ȭ �Լ�
	virtual void release();			//�޸� ���� �Խ�
	virtual void update();			//�����ϴ� �Լ�
	virtual void render(HDC hdc);	//�׸��� �Լ�

	void snakeMove();
	

};

