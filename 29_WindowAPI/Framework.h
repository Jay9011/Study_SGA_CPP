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

#define COLOR_WHITE RGB(255, 255, 255)
#define COLOR_BLACK RGB(  0,   0,   0)

#define COLOR_RED   RGB(255,   0,   0)
#define COLOR_GREEN RGB(  0, 255,   0)
#define COLOR_BLUE  RGB(  0,   0, 255)

//Utility
#include "Vector2.h"

//Object
#include "Point.h"
#include "Rect.h"
#include "Circle.h"
#include "Line.h"

//GameObject
#include "Tank.h"

//Utility
#include "Math.h"

using namespace Math;

//Scene
#include "Scene.h"
#include "PaintScene.h"
#include "CollisionScene.h"
#include "FortressScene.h"

#include "MainGame.h"

extern Point mousePos;
extern HWND hWnd;