#pragma once

//선 그려주는 함수    (뿌려줄 DC, 시작점 X, Y, 끝점 X, Y)
inline void LineMake(HDC hdc, int x1, int y1, int x2, int y2)
{
	MoveToEx(hdc, x1, y1, NULL);
	LineTo(hdc, x2, y2);
}

//사각형 그려주는 매크로함수 (뿌려줄DC, 시작점 X(left), 시작점Y(top), 가로크기, 세로크기)
inline void RectangleMake(HDC hdc, int x, int y, int width, int height)
{
	Rectangle(hdc, x, y, x + width, y + height);
}

//사각형 그려주는 매크로함수 (뿌려줄DC, 중점X(left), 중점Y(top), 가로크기, 세로크기)
inline void RectangleMakeCenter(HDC hdc, int x, int y, int width, int height)
{
	Rectangle(hdc, x - (width / 2), y - (height / 2), x + (width / 2), y + (height / 2));
}

//원 그려주는 매크로함수 (뿌려줄DC, 시작점 X(left), 시작점Y(top), 가로크기, 세로크기)
inline void EllipseMake(HDC hdc, int x, int y, int width, int height)
{
	Ellipse(hdc, x, y, x + width, y + height);
}

//원 그려주는 매크로함수 (뿌려줄DC, 중점X(left), 중점Y(top), 가로크기, 세로크기)
inline void EllipseMakeCenter(HDC hdc, int x, int y, int width, int height)
{
	Ellipse(hdc, x - (width / 2), y - (height / 2), x + (width / 2), y + (height / 2));
}