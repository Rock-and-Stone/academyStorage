#pragma once
#include "gameNode.h"
#include "ship.h"
#include "action.h"

class battle;

class starScene : public gameNode
{
private:
	ship* _battle;

	action* _action;
	image* _actionImage;

public:
	starScene();
	~starScene();

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();
};

