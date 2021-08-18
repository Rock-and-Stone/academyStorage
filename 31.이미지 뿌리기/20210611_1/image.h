#pragma once
class image
{
public:
	enum IMAGE_LOAD_KIND
	{
		LOAD_RESOURCE,		//���ҽ� ���Ϸκ���
		LOAD_FILE,			//�̹��� ���Ϸκ���
		LOAD_EMPTY,			//�� ��Ʈ�� �̹���
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

	//�� DC������ ���� �ʱ�ȭ �Լ�
	HRESULT init(int width, int height);
	HRESULT init(const char* fileName, int width, int height,
		BOOL trans = FALSE, COLORREF transColor = FALSE);
	//�޸� ���� �Լ�
	void release();
	//�׷��� �Լ�(�ѷ���DC, �ѷ�����ǥ(left, top)
	void render(HDC hdc, int destX, int destY);

	//�̹� �̹��� ����� ���ƴµ� �����ؾ��� �ȼ����� �ٲ���Ѵٸ�
	void setTransColor(BOOL trans, COLORREF transColor);

	inline HDC getMemDC() { return _imageInfo->hMemDC; }
};

