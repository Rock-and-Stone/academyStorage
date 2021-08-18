#pragma once
class image
{
public:
	typedef struct tagImageInfo
	{
		HDC		hMemDC;
		HBITMAP hBit;
		HBITMAP hOBit;
		int		width;
		int		height;

		tagImageInfo()
		{
			hMemDC = NULL;
			hBit = NULL;
			hOBit = NULL;
			width = 0;
			height = 0;
		}
	}IMAGE_INFO, *LPIMAGE_INFO;

private:
	LPIMAGE_INFO _backBuffer;

public:
	image();
	~image();

	//빈 DC영역을 만들 초기화 함수
	HRESULT init(int width, int height);
	//메모리 해제 함수
	void release();
	//그려줄 함수(뿌려줄DC, 뿌려줄좌표(left, top)
	void render(HDC hdc, int destX, int destY);

	inline HDC getMemDC() { return _backBuffer->hMemDC; }
};

