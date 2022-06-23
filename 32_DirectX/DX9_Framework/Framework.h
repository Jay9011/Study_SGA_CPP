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
#define DEVICE		Manager::Get()->GetDevice()->GetDevice()
#define WIN_WIDTH	1280
#define WIN_HEIGHT	720

extern HWND hWnd;

using namespace std;

/*
* System
*/
#include "System/Device.h"
#include "System/Keyboard.h"

// Singleton Manager
#include "System/Manager.h"

/*
* Scene
*/
#include "Scene/IScene.h"
//
#include "Scene/VertexScene/VertexScene.h"
#include "Scene/Scenes/WVPScene.h"


#include "MainGame.h"
