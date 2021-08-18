#pragma once
#include "gameNode.h"

enum PLAYERDIRECTION
{
	RIGHT_IDLE,
	LEFT_IDLE,
	RIGHT_RUN,
	LEFT_RUN
};

struct tagPlayer
{
	image* img;
	RECT rc;
	PLAYERDIRECTION direction;
	float x, y;
};


class playGround : public gameNode
{
private:
	image* _idle;
	image* _run;

	tagPlayer _player;

	int _count, _index;
	
	
public:
	playGround();
	~playGround();

	virtual HRESULT init();			//�ʱ�ȭ �Լ�
	virtual void release();			//�޸� ���� �Խ�
	virtual void update();			//�����ϴ� �Լ�
	virtual void render(HDC hdc);	//�׸��� �Լ�


};

