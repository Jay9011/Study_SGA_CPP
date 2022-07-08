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
#include <functional>
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
// Get Instance
#define DEVICE		Manager::Get()->GetDevice()->GetDevice()
#define TEXTURE		Manager::Get()->GetTextures()
#define KEYBOARD	Manager::Get()->GetKeyboard()
// Keyboard
#define KEYPRESS(p)	Manager::Get()->GetKeyboard()->Press(p)
#define KEYDOWN(p)	Manager::Get()->GetKeyboard()->Down(p)
#define KEYUP(p)	Manager::Get()->GetKeyboard()->Up(p)

#define PI D3DX_PI

#define V_LEFT  Vector2(-1 ,  0)
#define V_RIGHT Vector2(+1 ,  0)
#define V_UP    Vector2( 0 , -1)
#define V_DOWN  Vector2( 0 , +1)

using namespace std;

typedef D3DXVECTOR2	Vector2;
typedef D3DXVECTOR3	Vector3;
typedef D3DXVECTOR4	Vector4;
typedef D3DXMATRIX	Matrix;

const wstring texturePath = L"Textures/";
const string  knightPath  = "Textures/Knight/";

extern HWND hWnd;
extern D3DXVECTOR2 mousePos;

/*
* System
*/
#include "System/Math.h"
#include "System/Time.h"
#include "System/Device.h"
#include "System/Keyboard.h"
#include "System/Transform.h"
#include "System/Texture.h"
#include "System/TextureManager.h"
#include "System/Animation/Animation.h"
#include "System/XML.h"
// Collider
#include "System/Collider.h"
#include "System/Collider/ColliderBox.h"
#include "System/Collider/ColliderCircle.h"
// Singleton Manager
#include "System/Manager.h"

/*
* Object
*/
#include "GameObject/Planet.h"
#include "GameObject/Mario.h"
#include "GameObject/Knight.h"

/*
* Scene
*/
#include "Scene/IScene.h"
//
#include "Scene/VertexScene/VertexScene.h"
#include "Scene/Scenes/WVPScene.h"
#include "Scene/Scenes/SolarSystemScene.h"
#include "Scene/Scenes/TextureScene.h"
#include "Scene/Scenes/CollisionScene.h"
#include "Scene/Scenes/AnimationScene.h"


#include "MainGame.h"
