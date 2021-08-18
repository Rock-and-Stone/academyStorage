#pragma once
class image
{
public:
	enum IMAGE_LOAD_KIND
	{
		LOAD_RESOURCE,		//리소스 파일로부터
		LOAD_FILE,			//이미지 파일로부터
		LOAD_EMPTY,			//빈 비트맵 이미지
		LOAD_END
	};

	typedef struct tagImageInfo
	{						
		DWORD	resID;		
		HDC		hMemDC;
		HBITMAP hBit;
		HBITMAP hOBit;
		int		width;
		int		height;
		BYTE	loadType;

		tagImageInfo()
		{
			resID	= 0;
			hMemDC	= NULL;
			hBit	= NULL;
			hOBit	= NULL;
			width	= 0;
			height	= 0;
			loadType = LOAD_RESOURCE;
		}
	}IMAGE_INFO, *LPIMAGE_INFO;

private:
	LPIMAGE_INFO	_imageInfo;
	CHAR*			_fileName;
	BOOL			_trans;
	COLORREF		_transColor;

public:
	image();
	~image();

	//빈 DC영역을 만들 초기화 함수
	HRESULT init(int width, int height);
	HRESULT init(const char* fileName, int width, int height,
		BOOL trans = FALSE, COLORREF transColor = FALSE);
	//메모리 해제 함수
	void release();
	//그려줄 함수(뿌려줄DC, 뿌려줄좌표(left, top)
	void render(HDC hdc, int destX, int destY);

	//이미 이미지 등록을 마쳤는데 제거해야할 픽셀값을 바꿔야한다면
	void setTransColor(BOOL trans, COLORREF transColor);

	inline HDC getMemDC() { return _imageInfo->hMemDC; }
};

