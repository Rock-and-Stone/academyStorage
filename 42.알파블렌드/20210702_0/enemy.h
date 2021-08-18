#pragma once
#include "gameNode.h"

//���� �� �θ�Ŭ��

class enemy : public gameNode
{
protected:
	image* _imageName;	//���� ����� �̹��� �̸�
	RECT _rc;

	int _currentFrameX;	//������ ��ȣ�� ����� ����
	int _currentFrameY;

	int _count;				//���ʹ� ������ ī��Ʈ ��
	int _fireCount;			//�߻� �ð� ��
	int _rndFireCount;		//�����ϰ� �߻��Ҷ� �ð� ��
public:
	enemy();
	~enemy();

	virtual HRESULT init();
	virtual HRESULT init(const char* imageName, POINT position);
	virtual void release();
	virtual void update();
	virtual void render();

	void move();
	void draw();

	bool bulletCountFire();

	//���ʹ� ��Ʈ�� ���� ������
	inline RECT getRect() { return _rc; }
};

