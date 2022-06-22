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
// Direct3D
#include <d3d9.h>
#include <d3dx9.h>


/*
* FrameWork
*/
#include "Framework/Device.h"

// Singleton Manager
#include "Framework/Manager.h"


/*
* Scene
*/
#include "Scene/IScene.h"
//
#include "Scene/VertexScene/VertexScene.h"


#include "MainGame.h"


/*
*	Define
*/
#define DEVICE Manager::Get()->GetDevice()->GetDevice()


/*
*	lib
*/
#pragma comment(lib, "d3d9.lib")
#pragma comment(lib, "d3dx9.lib")

extern HWND hWnd;