#pragma once
#include "gameNode.h"
#include <vector>

struct tagBullet
{
	image* bulletImage;		//�Ѿ��� �̹���
	RECT rc;				//�Ѿ��� ��Ʈ
	float x, y;				//�Ѿ��� ����
	float angle;			//�Ѿ��� ����
	float radius;			//�Ѿ��� ������
	float speed;			//�Ѿ��� ���ǵ�
	float fireX, fireY;		//�Ѿ��� �߻���ġ
	bool isFire;			//�Ѿ��� �߻�����
	int count;
};

//������ ��� (�����ΰ� �߻��ϴ� �̜X)
class missile : public gameNode
{
private:
	vector<tagBullet>			_vBullet;
	vector<tagBullet>::iterator _viBullet;

	float _range;		//�̻��� ��Ÿ�(��?)

public:
	missile() {}
	~missile() {}

	virtual HRESULT init(int bulletMax, float range);
	virtual void release();
	virtual void update();
	virtual void render();

	//�Ѿ� �߻� �Լ�
	void fire(float x, float y);

	//�Ѿ� �����̴� �Լ�
	void move();

};


//�� �����ϴ� ���
class hellFire : public gameNode
{
private:
	vector<tagBullet> _vBullet;
	vector<tagBullet>::iterator _viBullet;

	float _range;
	int _bulletMax;

public:
	hellFire() {};
	~hellFire() {};


	virtual HRESULT init(int bulletMax, float range);
	virtual void release();
	virtual void update();
	virtual void render();

	void fire(float x, float y);
	void move();

};