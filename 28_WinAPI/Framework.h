// header.h: 표준 시스템 포함 파일
// 또는 프로젝트 특정 포함 파일이 들어 있는 포함 파일입니다.
//

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
#include <string>

using namespace std;


#define COLOR_RED   RGB(255, 0, 0)
#define COLOR_GREEN RGB(0, 255, 0)
#define COLOR_BLUE  RGB(0, 0, 255)

#define COLOR_BLACK RGB(0, 0, 0)
#define COLOR_WHITE RGB(255, 255, 255)
