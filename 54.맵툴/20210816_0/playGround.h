#pragma once
#include "gameNode.h"

#define TILESIZE 32	//타일 사이즈 32X32

#define TILEX 20	//가로 타일 갯수
#define TILEY 20	//세로 타일 갯수

//타일 규격 20 X 32 사이즈니까 -> 총 사이즈는 640 X 640
#define TILESIZEX TILESIZE * TILEX
#define TILESIZEY TILESIZE * TILEY

//타일 셋 가로 20줄 세로 9줄
#define SAMPLETILEX 20
#define SAMPLETILEY 9

//지형
enum TERRAIN
{
	TR_CEMENT, TR_DESERT, TR_GRASS, TR_WATER, TR_END
};

//오브젝트
enum OBJECT
{
	OBJ_BLOCK1, OBJ_BLOCK3, OBJ_BLOCKS,
	OBJ_FLAG1, OBJ_FLAG2,
	OBJ_TANK1, OBJ_TANK2, OBJ_NONE
};

enum POS
{
	//1P진영 깃발(독수리 모양) 1P 탱크 리스폰 위치
	POS_FLAG1, POS_FLAG2, POS_TANK1, POS_TANK2
};

//타일 구조체 (타일 정보등을 담고있다)
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

//타일 셋
struct tagSampleTile
{
	RECT rcTile;
	int terrainFrameX;
	int terrainFrameY;
};

//현재 무슨타일 찍었는지
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

	virtual HRESULT init();			//초기화 함수
	virtual void release();			//메모리 해제 함슈
	virtual void update();			//연산하는 함수
	virtual void render();			//그리기 함수

	virtual void setup();
	virtual void setMap();

	virtual void save();
	virtual void load();

	TERRAIN terrainSelect(int frameX, int frameY);
	OBJECT objSelect(int frameX, int frameY);
	
};

