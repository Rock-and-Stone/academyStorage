#pragma once
#include "gameNode.h"

class pixelCollision : public gameNode
{
private:
	image* _mountain;	//배경 이미지
	image* _ball;		// 공 이미지

	RECT _rc;			//렉트
	float _x, _y;		//중점좌표
	int _probeY;		//Y축 탐사

public:
	pixelCollision();
	~pixelCollision();

	HRESULT init();
	void release();
	void update();
	void render();
};

