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
#include <vector>
#include <map>
#include <string>
#include <functional>

using namespace std;

#include <d3d9.h>
#include <d3dx9.h>

#pragma comment(lib, "d3d9.lib")
#pragma comment(lib, "d3dx9.lib")

#include <AntTweakBar.h>

#define WIN_WIDTH 1280
#define WIN_HEIGHT 720

#define WIN_CENTER_X WIN_WIDTH  * 0.5
#define WIN_CENTER_Y WIN_HEIGHT * 0.5

#define DEVICE    Device::Get()->GetDevice()
#define TEXTURE  Manager::Get()->GetTextures()
#define KEYBOARD Manager::Get()->GetKeyboard()
#define EFFECTS  Manager::Get()->GetEffects()

#define KEYPRESS(p) Manager::Get()->GetKeyboard()->Press(p)
#define KEYDOWN(p)  Manager::Get()->GetKeyboard()->Down(p)
#define KEYUP(p)    Manager::Get()->GetKeyboard()->Up(p)

#define PI D3DX_PI

#define V_LEFT  Vector2(-1 ,  0)
#define V_RIGHT Vector2(+1 ,  0)
#define V_UP    Vector2( 0 , -1)
#define V_DOWN  Vector2( 0 , +1)

typedef D3DXVECTOR2 Vector2;
typedef D3DXVECTOR3 Vector3;
typedef D3DXVECTOR4 Vector4;
typedef D3DXMATRIX  Matrix;

const  string  knightPath =  "Textures/Knight/";
const wstring texturePath = L"Textures/";

#include "System/Device.h"
#include "System/Keyboard.h"
#include "System/Transform.h"
#include "System/Shader.h"
#include "System/Texture.h"
#include "System/TextureManager.h"
#include "System/Math.h"
#include "System/Time.h"
#include "System/Animation.h"
#include "System/XML.h"
#include "System/TweakBar.h"
#include "System/Effect.h"
#include "System/EffectManager.h"
#include "System/Object.h"
#include "System/Camera.h"

#include "System/Collider.h"
#include "System/ColliderBox.h"
#include "System/ColliderCircle.h"

#include "System/Manager.h"

#include "GameObject/Planet.h"
#include "GameObject/Mario.h"
#include "GameObject/Knight.h"

#include "Scene/Scene.h"
#include "Scene/VertexScene.h"
#include "Scene/WVPScene.h"
#include "Scene/SolarSystemScene.h"
#include "Scene/TextureScene.h"
#include "Scene/CollisionScene.h"
#include "Scene/AnimationScene.h"
#include "Scene/ShaderScene.h"
#include "Scene/MultiShaderScene.h"

#include "MainGame.h"

extern HWND hWnd;
extern Vector2 mousePos;