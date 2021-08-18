#pragma once
#include "gameNode.h"

#define PI 3.14156f
#define BULLETMAX 30

struct tagBullet
{
	float x, y;		//중점 좌표
	float speed;	//총알 속도
	float angle;	//총알 각도
	float radius;	//반지름
	bool isFire;	//발사했늬?
	float gravity;
};

struct tagCannon
{
	POINT center;		//중점
	POINT cannonEnd;	//끝점
	int radius;			//반지름
	int cannon;			//길이 (?)
	float angle;		//각도
};


class playGround : public gameNode
{
private:
	tagCannon _cannon;
	tagBullet _bullet[BULLETMAX];
	
public:
	playGround();
	~playGround();

	virtual HRESULT init();			//초기화 함수
	virtual void release();			//메모리 해제 함슈
	virtual void update();			//연산하는 함수
	virtual void render(HDC hdc);	//그리기 함수

	
	void bulletFire();
	void bulletMove();

};

