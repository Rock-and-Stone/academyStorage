#include "pch.h"
#include "image.h"


image::image()
	: _imageInfo(NULL),
	_fileName(NULL),
	_trans(false),
	_transColor(RGB(0,0,0))
{
}


image::~image()
{
}

HRESULT image::init(int width, int height)
{
	//뭔가가 미리 정의되어있다면 메모리 해제 해주어라
	if (_imageInfo != NULL) release();

	HDC hdc = GetDC(_hWnd);

	_imageInfo = new IMAGE_INFO;
	_imageInfo->hMemDC = CreateCompatibleDC(hdc);
	_imageInfo->hBit = (HBITMAP)CreateCompatibleBitmap(hdc, width, height);
	_imageInfo->hOBit = (HBITMAP)SelectObject(_imageInfo->hMemDC, _imageInfo->hBit);
	_imageInfo->width = width;
	_imageInfo->height = height;

	if (_imageInfo == nullptr)
	{
		release();

		return E_FAIL;
	}

	ReleaseDC(_hWnd, hdc);

	return S_OK;
}

HRESULT image::init(const char * fileName, int width, int height, BOOL trans, COLORREF transColor)
{
	if (_imageInfo != nullptr) release();

	HDC hdc = GetDC(_hWnd);

	_imageInfo = new IMAGE_INFO;
	_imageInfo->loadType = LOAD_FILE;
	_imageInfo->resID = 0;
	_imageInfo->hMemDC = CreateCompatibleDC(hdc);	//빈 DC 영역을 생성
	_imageInfo->hBit = (HBITMAP)LoadImage(_hInstance, fileName, IMAGE_BITMAP, width, height, LR_LOADFROMFILE);
	_imageInfo->hOBit = (HBITMAP)SelectObject(_imageInfo->hMemDC, _imageInfo->hBit);
	_imageInfo->width = width;
	_imageInfo->height = height;

	int len = strlen(fileName);

	_fileName = new CHAR[len + 1];
	strcpy_s(_fileName, len + 1, fileName);

	_trans = trans;
	_transColor = transColor;

	if (_imageInfo->hBit == NULL)
	{
		release();

		return E_FAIL;
	}
	   	 
	ReleaseDC(_hWnd, hdc);

	return S_OK;
}

void image::release()
{
	if (_imageInfo)
	{
		SelectObject(_imageInfo->hMemDC, _imageInfo->hOBit);
		DeleteObject(_imageInfo->hBit);
		DeleteDC(_imageInfo->hMemDC);

		SAFE_DELETE(_imageInfo);
		SAFE_DELETE(_fileName);

		_trans = false;
		_transColor = RGB(0, 0, 0);
	}
}


void image::setTransColor(BOOL trans, COLORREF transColor)
{
	_trans = trans;
	_transColor = transColor;
}

void image::render(HDC hdc)
{
	if (_trans)
	{
		GdiTransparentBlt(
			hdc,					//복사될 영역의 DC
			0,					//복사될 좌표(left)
			0,					//복사될 좌표(top)
			_imageInfo->width,		//복사될 크기 (가로크기)
			_imageInfo->height,		//복사될 크기 (세로크기)
			_imageInfo->hMemDC,		//복사해올 DC
			0, 0,					//복사해올 시작좌표(left, top)
			_imageInfo->width,		//복사해올 크기(가로)
			_imageInfo->height,		// 			(세로)
			_transColor);			//복사할때 제외할 픽셀값
	}
	else
	{
		//BitBlt == DC영역간의 고속복사를 해주는 함수
		BitBlt(
			hdc,				//복사될 DC
			0,				//복사될 좌표 (left)
			0,				//복사될 좌표 (top)
			_imageInfo->width,	//복사될 크기
			_imageInfo->height,
			_imageInfo->hMemDC,//복사해올 DC
			0, 0,				//복사시작될 좌표(left, top)
			SRCCOPY);			//변형없이 복사한다
	}

}



void image::render(HDC hdc, int destX, int destY)
{
	if (_trans)
	{
		GdiTransparentBlt(
			hdc,					//복사될 영역의 DC
			destX,					//복사될 좌표(left)
			destY,					//복사될 좌표(top)
			_imageInfo->width,		//복사될 크기 (가로크기)
			_imageInfo->height,		//복사될 크기 (세로크기)
			_imageInfo->hMemDC,		//복사해올 DC
			0, 0,					//복사해올 시작좌표(left, top)
			_imageInfo->width,		//복사해올 크기(가로)
			_imageInfo->height,		// 			(세로)
			_transColor	);			//복사할때 제외할 픽셀값
	}
	else
	{
		//BitBlt == DC영역간의 고속복사를 해주는 함수
		BitBlt(
			hdc,				//복사될 DC
			destX,				//복사될 좌표 (left)
			destY,				//복사될 좌표 (top)
			_imageInfo->width,	//복사될 크기
			_imageInfo->height,
			_imageInfo->hMemDC,//복사해올 DC
			0, 0,				//복사시작될 좌표(left, top)
			SRCCOPY);			//변형없이 복사한다
	}
	

}

void image::render(HDC hdc, int destX, int destY, int sourX, int sourY, int sourWidth, int sourHeight)
{
	if (_trans)
	{
		GdiTransparentBlt(
			hdc,					//복사될 영역의 DC
			destX,					//복사될 좌표(left)
			destY,					//복사될 좌표(top)
			sourWidth,				//복사될 크기 (가로크기)
			sourHeight,				//복사될 크기 (세로크기)
			_imageInfo->hMemDC,		//복사해올 DC
			sourX, sourY,					//복사해올 시작좌표(left, top)
			sourWidth,				//복사해올 크기(가로)
			sourHeight,				// 			(세로)
			_transColor);			//복사할때 제외할 픽셀값
	}
	else
	{
		//BitBlt == DC영역간의 고속복사를 해주는 함수
		BitBlt(
			hdc,				//복사될 DC
			destX,				//복사될 좌표 (left)
			destY,				//복사될 좌표 (top)
			sourWidth,			//복사될 크기
			sourHeight,
			_imageInfo->hMemDC,//복사해올 DC
			sourX, sourY,		//복사시작될 좌표(left, top)
			SRCCOPY);			//변형없이 복사한다
	}

}

