#pragma once

#include "targetver.h"
#define WIN32_LEAN_AND_MEAN             // 거의 사용되지 않는 내용을 Windows 헤더에서 제외합니다.
// Windows 헤더 파일
#include <windows.h>
// C 런타임 헤더 파일입니다.
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>
#include <iostream>

using namespace std;

#include "commonMacroFunction.h"

//========================================
// ## 윈도우 설정 디파인문 ## 2021.05.26 ##
//========================================

#define WINNAME		(LPTSTR)TEXT("Class29")			//윈도우 이름
#define WINSTARTX	2000								//윈도우 시작좌표(left)
#define WINSTARTY	50								//윈도우 시작좌표(top)
#define WINSIZEX	1024							//윈도우 가로크기
#define WINSIZEY	768								//윈도우 세로크기
#define WINSTYLE	WS_CAPTION | WS_SYSMENU