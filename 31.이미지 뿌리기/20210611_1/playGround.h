#pragma once
#include "gameNode.h"

struct tagSmile
{
	image* img;
	RECT rc;
	float jumpPower;
	float gravity;
};

class playGround : public gameNode
{
private:
	image* _day;
	image* _night;
	image* _background;

	tagSmile _smile;

	int _count;
	bool _isDay;
	
public:
	playGround();
	~playGround();

	virtual HRESULT init();			//�ʱ�ȭ �Լ�
	virtual void release();			//�޸� ���� �Խ�
	virtual void update();			//�����ϴ� �Լ�
	virtual void render(HDC hdc);	//�׸��� �Լ�


};

