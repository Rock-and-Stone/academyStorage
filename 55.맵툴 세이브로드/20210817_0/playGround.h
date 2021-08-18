#pragma once
#include "gameNode.h"

#define TILESIZE 32	//Ÿ�� ������ 32X32

#define TILEX 20	//���� Ÿ�� ����
#define TILEY 20	//���� Ÿ�� ����

//Ÿ�� �԰� 20 X 32 ������ϱ� -> �� ������� 640 X 640
#define TILESIZEX TILESIZE * TILEX
#define TILESIZEY TILESIZE * TILEY

//Ÿ�� �� ���� 20�� ���� 9��
#define SAMPLETILEX 20
#define SAMPLETILEY 9

//����
enum TERRAIN
{
	TR_CEMENT, TR_DESERT, TR_GRASS, TR_WATER, TR_END
};

//������Ʈ
enum OBJECT
{
	OBJ_BLOCK1, OBJ_BLOCK3, OBJ_BLOCKS,
	OBJ_FLAG1, OBJ_FLAG2,
	OBJ_TANK1, OBJ_TANK2, OBJ_NONE
};

enum POS
{
	//1P���� ���(������ ���) 1P ��ũ ������ ��ġ
	POS_FLAG1, POS_FLAG2, POS_TANK1, POS_TANK2
};

//Ÿ�� ����ü (Ÿ�� �������� ����ִ�)
struct tagTile
{
	TERRAIN terrain;
	OBJECT obj;
	RECT rc;
	int terrainFrameX;
	int terrainFrameY;
	int objFrameX;
	int objFrameY;
};

//Ÿ�� ��
struct tagSampleTile
{
	RECT rcTile;
	int terrainFrameX;
	int terrainFrameY;
};

//���� ����Ÿ�� �������
struct tagCurrentTile
{
	int x;
	int y;
};

class playGround : public gameNode
{
private:
	HWND _btnSave;
	HWND _btnLoad;
	HWND _btnTerrainDraw;
	HWND _btnObjectDraw;
	HWND _btnEraser;

	tagCurrentTile _currentTile;
	tagSampleTile _sampleTile[SAMPLETILEX * SAMPLETILEY];
	tagTile _tiles[TILEX * TILEY];

	int _pos[2];

public:
	playGround();
	~playGround();

	virtual HRESULT init();			//�ʱ�ȭ �Լ�
	virtual void release();			//�޸� ���� �Խ�
	virtual void update();			//�����ϴ� �Լ�
	virtual void render();			//�׸��� �Լ�

	virtual void setup();
	virtual void setMap();

	virtual void save();
	virtual void load();

	TERRAIN terrainSelect(int frameX, int frameY);
	OBJECT objSelect(int frameX, int frameY);
	
};

