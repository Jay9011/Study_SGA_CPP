#pragma once

#include "targetver.h"
#define WIN32_LEAN_AND_MEAN            
#include <windows.h>
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>

#include <vector>
#include <map>

#include <iostream>
#include <string>
#include <stdlib.h>
#include <Windows.h>
#include <cmath>

using namespace std;

#define COLOR_WHITE	   RGB(255, 255, 255)
#define COLOR_BLACK	   RGB(  0,   0,   0)
					   
#define COLOR_RED	   RGB(255,   0,   0)
#define COLOR_GREEN	   RGB(  0, 255,   0)
#define COLOR_BLUE	   RGB(  0,   0, 255)
					   
#define COLOR_CYAN	   RGB(  0, 255, 255)
#define COLOR_MAGENTA  RGB(255,   0, 255)
#define COLOR_YELLOW   RGB(255, 255,   0)
					   
#define COLOR_GRAY 	   RGB(128, 128, 128)
#define COLOR_ORANGE   RGB(255, 168,   0)
#define COLOR_PINK     RGB(255, 192, 203)

#define PI	3.1415926536

//#define	WIN_WIDTH	1280	// 설정한 윈도우 가로
//#define	WIN_HEIGHT	720		// 설정한 윈도우 세로
#define	WIN_WIDTH		600					// SGA Arkanoid 전용 윈도우 가로 크기
#define	WIN_HEIGHT		800					// SGA Arkanoid 전용 윈도우 세로 크기
#define WIN_CENTER_X	WIN_WIDTH  * 0.5	// SGA Arkanoid 전용 윈도우 가로 크기
#define WIN_CENTER_Y	WIN_HEIGHT * 0.5	// SGA Arkanoid 전용 윈도우 세로 크기

//Utility
#include "Vector2.h"

//Object
#include "Point.h"
#include "Rect.h"
#include "Circle.h"
#include "Line.h"

//Utility
#include "Math.h"
using namespace Math;
#include "Collision.h"

//GameObject
#include "CannonBall.h"
#include "CannonBallManager.h"
#include "Tank.h"

#include "AKUI.h"
#include "AKBrick.h"
#include "AKBall.h"
#include "AKBallManager.h"
#include "AKPlayer.h"
#include "AKStageManager.h"
#include "AKCollisionManager.h"

#include "SGABar.h"
#include "SGABall.h"
#include "SGABrick.h"

//Scene
#include "Scene.h"
#include "PaintScene.h"
#include "CollisionScene.h"
#include "FortressScene.h"
#include "ArkanoidScene.h"
#include "SGAArkanoidScene.h"

#include "MainGame.h"

extern Vector2 mousePos;
extern HWND hWnd;