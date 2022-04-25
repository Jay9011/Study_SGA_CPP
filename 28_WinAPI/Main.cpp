#include "Framework.h"
#include "Main.h"

#define MAX_LOADSTRING 100

/*
Window 데스크톱 어플리케이션

Window API

Application Programming Interface

어플리케이션 개발 환경

wWinMain : main함수와 같다고 생각하면 된다.

역할 

1. window 창 생성 및 옵션 설정(어떤 크기로 어떤 위치에 생성할 지)

2. message 루프 돌린다


핸들(handle) : 핸들을 제공 받으면 특정 기능을 사용할 수 있게 된다. 이 기능을 사용할 때 필요한 도구다

ASCII CODE : 멀티바이트 문자 집합, 1byte char형, 영어는 1바이트, 한글은 2바이트로 처리

UNICODE(Universe Code) : 유니코드 문자 집합, 2byte char형, 모든 언어를 2바이트로 처리


WS_OVERLAPPEDWINDOW

WS_OVERLAPPED  : DEFAULT. 기본값
WS_CAPTION     : 타이틀 바를 가진다
WS_SYSMENU     : 시스템 메뉴를 가진다
WS_THICKFRAME  : 크기를 조절하는 경계선을 가진다
WS_MINIMIZEBOX : 최소화 버튼을 가진다
WS_MAXIMIZEBOX : 최대화 버튼을 가진다

WS_HSCROLL     : 수평 스크롤을 가진다
WS_VSCROLL     : 수직 스크롤을 가진다


WndProc 함수의 매개변수

hWnd, message, wParam, lParam

hWnd: 윈도우의 핸들, 윈도우 창을 조정할 수 있는 핸들

message: 윈도우가 입력받은 메세지, 메세지를 포괄적으로 담고 있다

wParam: 어떤 키가 입력되었는지

lParam: 마우스의 위치 정보


WM_PAINT -> 실질적인 화면 출력을 담당

HDC: Handle Device Context, 화면 출력을 담당하는 핸들


*/


// 전역 변수:
HINSTANCE hInst;                                // 현재 인스턴스입니다.
WCHAR szTitle[MAX_LOADSTRING];                  // 제목 표시줄 텍스트입니다.
WCHAR szWindowClass[MAX_LOADSTRING];            // 기본 창 클래스 이름입니다.

HPEN   redPen;
HPEN  bluePen;
HPEN greenPen;

HBRUSH     hBrush;
HBRUSH  blueBrush;
HBRUSH greenBrush;

// 이 코드 모듈에 포함된 함수의 선언을 전달합니다:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: 여기에 코드를 입력합니다.

    // 전역 문자열을 초기화합니다.
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_MY28WINAPI, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // 애플리케이션 초기화를 수행합니다:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_MY28WINAPI));

    MSG msg;

    // 기본 메시지 루프입니다:
    while (GetMessage(&msg, nullptr, 0, 0))
    {
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }

    return (int) msg.wParam;
}



//
//  함수: MyRegisterClass()
//
//  용도: 창 클래스를 등록합니다.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_MY28WINAPI));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_MY28WINAPI);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

//
//   함수: InitInstance(HINSTANCE, int)
//
//   용도: 인스턴스 핸들을 저장하고 주 창을 만듭니다.
//
//   주석:
//
//        이 함수를 통해 인스턴스 핸들을 전역 변수에 저장하고
//        주 프로그램 창을 만든 다음 표시합니다.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // 인스턴스 핸들을 전역 변수에 저장합니다.

   HWND hWnd = CreateWindowW
   (
       szWindowClass,
       szTitle,
       WS_OVERLAPPEDWINDOW,
       CW_USEDEFAULT, 0, 
       CW_USEDEFAULT, 0, 
       nullptr, nullptr, hInstance, nullptr);

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

//
//  함수: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  용도: 주 창의 메시지를 처리합니다.
//
//  WM_COMMAND  - 애플리케이션 메뉴를 처리합니다.
//  WM_PAINT    - 주 창을 그립니다.
//  WM_DESTROY  - 종료 메시지를 게시하고 반환합니다.
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_CREATE:
        {
              redPen = CreatePen(PS_SOLID, 1, COLOR_RED);
             bluePen = CreatePen(PS_SOLID, 1, COLOR_BLUE);
            greenPen = CreatePen(PS_SOLID, 1, COLOR_GREEN);

             blueBrush = CreateSolidBrush(COLOR_BLUE);
            greenBrush = CreateSolidBrush(COLOR_GREEN);
        }
    case WM_COMMAND:
        {
            int wmId = LOWORD(wParam);
            // 메뉴 선택을 구문 분석합니다:
            switch (wmId)
            {
            case IDM_ABOUT:
                DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
                break;
            case IDM_EXIT:
                DestroyWindow(hWnd);
                break;
            default:
                return DefWindowProc(hWnd, message, wParam, lParam);
            }
        }
        break;
    case WM_KEYDOWN:
        {        
            switch (wParam)
            {
            case '1':
                hBrush = blueBrush;
                break;
            case '2':
                hBrush = greenBrush;
                break;
            default:
                break;
            }

            InvalidateRect(hWnd, nullptr, true);
        }
        break;
    case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);
            
            //글자 출력
            wstring str = L"Hello World!";

            TextOut(hdc, 100, 100, str.c_str(), str.size());

            
            //픽셀 출력
            for (UINT i = 0; i < 50; i++)
            {
                SetPixel(hdc, 200 + i, 200, RGB(0, 0, 0));
            }

            //선 출력    
            SelectObject(hdc, redPen);

            MoveToEx(hdc, 200, 300, nullptr);  //시작점
            LineTo(hdc, 300, 400);             //끝점

            //사각형 출력
            SelectObject(hdc, bluePen);
            SelectObject(hdc, blueBrush);

            Rectangle
            (
                hdc,
                350, 200, 400, 250
            );

            //원 출력
            SelectObject(hdc, greenPen);
            SelectObject(hdc, greenBrush);

            Ellipse
            (
                hdc,
                350, 350, 400, 400
            );

            //키 입력 받을 도형
            SelectObject(hdc, hBrush);

            Rectangle(hdc, 600, 300, 700, 500);

            EndPaint(hWnd, &ps);
        }
        break;
    case WM_LBUTTONDOWN:
        {
            HDC hdc = GetDC(hWnd);

            int x = LOWORD(lParam);
            int y = HIWORD(lParam);

            //COLORREF color = RGB(255, 0, 0);

            SetPixel(hdc, x, y, COLOR_BLUE);
        }
        break;
    case WM_DESTROY:
        {
            DeleteObject(  redPen);
            DeleteObject( bluePen);
            DeleteObject(greenPen);
            
            DeleteObject( blueBrush);
            DeleteObject(greenBrush);

            PostQuitMessage(0);
        }
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

// 정보 대화 상자의 메시지 처리기입니다.
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
        return (INT_PTR)TRUE;

    case WM_COMMAND:
        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        break;
    }
    return (INT_PTR)FALSE;
}
