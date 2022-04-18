#pragma once

#include "targetver.h"
#define WIN32_LEAN_AND_MEAN            
#include <windows.h>
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>
#include <ctime>

#include <vector>
#include <map>
#include <list>

#include <iostream>
#include <string>


using namespace std;

#define COLOR_WHITE RGB(255, 255, 255)
#define COLOR_BLACK RGB(  0,   0,   0)

#define COLOR_RED   RGB(255,   0,   0)
#define COLOR_GREEN RGB(  0, 255,   0)
#define COLOR_BLUE  RGB(  0,   0, 255)

// Object
#include "Point.h"
#include "Object.h"
#include "Rect.h"
#include "Circle.h"

#include "Projectile.h"
#include "ProjectileList.h"

// Utility
#include "Math.h"

// Scene
#include "Scene.h"
#include "PaintScene.h"
#include "CollisionScene.h"

#include "MainGame.h"

extern Point mousePos;
extern HWND hWnd;