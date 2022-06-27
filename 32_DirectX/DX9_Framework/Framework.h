#pragma once
/*
*	lib
*/
#pragma comment(lib, "d3d9.lib")
#pragma comment(lib, "d3dx9.lib")

#include "targetver.h"
#define WIN32_LEAN_AND_MEAN             // 거의 사용되지 않는 내용을 Windows 헤더에서 제외합니다.
// Windows 헤더 파일
#include <windows.h>
// C 런타임 헤더 파일입니다.
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>
#include <string>
#include <vector>
#include <map>
// Direct3D
#include <d3d9.h>
#include <d3dx9.h>

/*
*	Define
*/
#define WIN_WIDTH	1280
#define WIN_HEIGHT	720
#define WIN_CENTER_X	WIN_WIDTH * 0.5
#define WIN_CENTER_Y	WIN_HEIGHT * 0.5
// D3D Device
#define DEVICE		Manager::Get()->GetDevice()->GetDevice()
// Keyboard
#define KEYPRESS(p)	Manager::Get()->GetKeyboard()->Press(p)
#define KEYDOWN(p)	Manager::Get()->GetKeyboard()->Down(p)
#define KEYUP(p)	Manager::Get()->GetKeyboard()->Up(p)

#define PI D3DX_PI

typedef D3DXVECTOR2	Vector2;
typedef D3DXVECTOR3	Vector3;
typedef D3DXVECTOR4	Vector4;
typedef D3DXMATRIX	Matrix;

extern HWND hWnd;

using namespace std;

/*
* System
*/
#include "System/Device.h"
#include "System/Keyboard.h"
#include "System/Transform.h"

// Singleton Manager
#include "System/Manager.h"

/*
* Object
*/
#include "GameObject/Planet.h"

/*
* Scene
*/
#include "Scene/IScene.h"
//
#include "Scene/VertexScene/VertexScene.h"
#include "Scene/Scenes/WVPScene.h"
#include "Scene/Scenes/SolarSystemScene.h"


#include "MainGame.h"
