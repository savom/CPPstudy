// 231118_WinAPI.cpp : 애플리케이션에 대한 진입점을 정의합니다.
// API : Application Programming Interface
// Application(APP) : 응용 프로그램(앱, exe.)
// Programming : 프로그래밍
// Interface : 환경
// 응용 프로그램을 프로그래밍하는 환경.
// => 응용 프로그램을 프로그래밍 할 수 있도록 제공하는 여러가지 기능들의 집합.

// ex) 카카오톡 API
// 카카오톡의 응용프로그램을 프로그래밍 할 수 있도록 카카오톡 회사에서 제공하는 기능

// WinAPI : 윈도우 API
// 윈도우 응용프래그램을 만드는 것.

#include "framework.h" // 응용 프로그램을 만들기 위한 헤더 모음집
#include "231118_WinAPI.h"

#define MAX_LOADSTRING 100

// 전역 변수:
// HINSTANCE : 응용 프로그램의 고유 번호.
// 같은 응용 프로그램끼리 구분하기 위해서 사용하는 번호.

HINSTANCE /* 응용 프로그램의 고유 번호(포인터) */ hInst;                                // 현재 인스턴스입니다.
// H(Handle) + INSTANCE(객체)
// Handle : 핸들. 조작. 
// = 고유 번호. 객체에 접근하기 위한 고유 번호(주소.포인터).

// WCHAR : W(wide 넓은) + CHAR(문자)
// WBCS : Wide Byte Character Set(고정 2바이트 크기.) : 메모리를 더 많이 사용.
// 영어든 뭐든 전부 2바이트.
// 문자와 관계 없이, 문자 연산이 비교적 편함.
// 
// 2바이트 크기의 문자 데이터 형식.
// char(SBCS, MBCS): 1바이트 크기의 문자 데이터 형식.
// SBCS : Single Byte Character Set
// MBCS : Multi Byte Character Set(1 ~ 4 바이트로 유동적인 크기) : 메모리를 적게 사용.
// 영어는 1바이트, 그 외 문자는 2 ~ 3바이트.
// 문자가 섞여있을 경우, 문자 연산이 어려움.(문자열 길이, 문자 더하기 등등)

 

WCHAR szTitle[MAX_LOADSTRING];                  // 제목 표시줄 텍스트입니다.
WCHAR szWindowClass[MAX_LOADSTRING];            // 기본 창 클래스 이름입니다.

// 이 코드 모듈에 포함된 함수의 선언을 전달합니다:
ATOM                MyRegisterClass(HINSTANCE hInstance); // 윈도우 등록 함수
BOOL                InitInstance(HINSTANCE, int); // 응용 프로그램 시작 함수

// 메세지 : 이벤트가 발생했을 때 운영체제가 프로그램으로 보내는 신호.
// 이벤트 : 사건.(키보드를 입력했을 때, 마우스를 입력했을 때, 윈도우를 생성/파괴했을 때 등등)

//운영체제가 보내는 모든 메세지는 '일단' 메시지 큐(Queue. 선입선출)로 이동!
// 메세지 큐 : 응용 프로그램이 메세지를 저장해두는 곳.
// 응용 프로그램은 메세지 큐에서 메세지를 하나씩 가져와서 순서대로 처리!
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM); // 메시지 처리 함수
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

// winMain : WinAPI에서 사용하는 main 함수
int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance); // 사용하지 않음
    UNREFERENCED_PARAMETER(lpCmdLine); // 사용하지 않음

    // TODO: 여기에 코드를 입력합니다.

    // 전역 문자열을 초기화합니다.
    // LoadString() : 문자열을 리소스에서 불러오는 함수.
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_MY231118WINAPI, szWindowClass, MAX_LOADSTRING);
    
    // 1. 윈도우 클래스 등록!
    MyRegisterClass(hInstance);

    // 2. 응용 프로그램 시작(= 윈도우를 생성하고 표시!)
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    // H(핸들) + ACCEL(단축키)
    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_MY231118WINAPI));

    // MSG : 메세지 구조체.
    MSG msg; // 처음에는 쓰레기 값이 들어있음.

    // 기본 메시지 루프입니다:
    // GetMessage([메세지를 저장할 구조체의 주소], [윈도우 핸들], [최소 값], [최대 값])
    // [윈도우 핸들] : 작성할 경우, 해당 윈도우의 메세지'만' 받음.
    // [최소 값], [최대 값] : 메세지의 최소 ~ 최대 범위.
    // 둘 다 0으로 되어 있을 경우, 모든 메세지를 받음. 
    // 
    // GetMessage() : Get(가져오다) + Message : 메세지를 메세지 큐에서 가져오는 함수! 
    // 가져온 메세지는 msg에 저장

    while (GetMessage(&msg, nullptr, 0, 0))
    {
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
        {
            // TranslateMessage() : 메세지를 번역하는 함수.
            // 메세지를 번역 : 메세지에 세부적인 정보를 추가!\
            // ex.
            // 메세지 : 야! 키보드 입력했어!
            // 세부 정보 : 왼쪽 방향 키(WPARAM, LPARAM에 저장됨)
            TranslateMessage(&msg);

            // DispatchMessage() : Dispatch(택배, 편지 등을 보내다!)
            // 메세지를 메세지 처리 함수(Wndproc)로 보내는 함수.
            // (WndProc를 호출!)
            DispatchMessage(&msg);
        }
    }

    return (int) msg.wParam;
}



//
//  함수: MyRegisterClass()
//
//  용도: 창 클래스를 등록합니다.
//  어떤 창을 만들지 미리 등록해 놓는 것.
// 
// 윈도우를 실제로 생성하려면, 먼저 윈도우를 등록해야 한다!
// 
// 응용 프로그램 != 윈도우(창)
// 응용 프로그램 안에 창이 있음.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
    // WNDCLASS : WND(Window의 줄임말) + CLASS 윈도우 클래스(구조체)
    WNDCLASSEXW wcex; // 처음에는 쓰레기 값이 들어있음.

    // 윈도우 구조체를 초기화.
    wcex.cbSize = sizeof(WNDCLASSEX); // 구조체의 메모리 크기

    wcex.style          = CS_HREDRAW | CS_VREDRAW; // 윈도우 스타일
    // CS_HREDRAW, CS_VREDRAW 
    // : H(Horizontal 수평의), V(Vertical 수직의) + REDRAW(다시 그린다.)
    // 창의 수평/수직 크기가 변경될 경우 다시 그림.

    // lpfn + WndProc : 함수 포인터. 메세지 처리 함수의 주소를 저장하는 포인터.
    // lp : long pointer(= 포인터)
    // fn : function 함수
    wcex.lpfnWndProc    = WndProc; // 메세지 처리 함수의 주소를 대입!
    wcex.cbClsExtra     = 0; // 거의 사용하지 않음
    wcex.cbWndExtra     = 0; // 거의 사용하지 않음
    // 응용 프로그램 고유 번호(등록하고 있는 윈도우의 주인을 알려줌)
    wcex.hInstance      = hInstance; // 현재 윈도우 구조체의 주인(응용 프로그램)을 작성

    // 아이콘, 커서를 불러와서 윈도우의 아이콘, 커서를 설정.
    // MAKE INT RESOURCE() : 정수 값을 리소스(자원)로 변경하는 매크로 함수.
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_MY231118WINAPI));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1); // 윈도우 배경 색 설정
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_MY231118WINAPI);

    // 윈도우를 생성할 때, 등록한 윈도우 클래스 이름으로 불러옴.
    // sz : 문자열
    wcex.lpszClassName  = szWindowClass; // 윈도우 클래스의 이름.

    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    // RegisterClass() : 윈도우 구조체를 등록하는 함수.
    return RegisterClassExW(&wcex); // 포인터 매개변수를 쓸 경우 1. 값을 바꿀려고 2. 구조체는 용량이 크니까 포인터를 쓴다. 이 경우는 후자
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

// 윈도우를 생성하고 표시!
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // 인스턴스 핸들을 전역 변수에 저장합니다.

   // HWND : H + WND : 윈도우 핸들(고유 번호)
   // CreateWindowW() : 윈도우를 생성하는 함수.
   // CreateWindowW([등록한 윈도우 이름], [제목 표시줄 텍스트], [윈도우 스타일], 
   // [윈도우 위치(x,y)], [윈도우 크기(width, height] )
   // WS : Window Style

   // CW_USEDEFAULT : CW(CreateWindow)_USEDEFAULT : 기본 값을 사용!
   HWND hWnd = CreateWindowW(szWindowClass, szTitle , WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 300, CW_USEDEFAULT, 5, nullptr, nullptr, hInstance, nullptr); // 반환 데이터 : 윈도우 핸들(윈도우를 생성 실패 시에는 NULL을 반환.)

   if (!hWnd) // '윈도우를 정상적으로 생성하지 못했다면' 이라는 뜻 (hwnd == 0)
   {
      return FALSE; // 프로그램 종료.
   }

   ShowWindow(hWnd, nCmdShow); // ShowWindow() : 윈도우를 보여주는 함수.
   UpdateWindow(hWnd); // 윈도우를 갱신(새로 고침)하는 함수.



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

// 메세지 처리!
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
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
    case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);
            // TODO: 여기에 hdc를 사용하는 그리기 코드를 추가합니다...
            EndPaint(hWnd, &ps);
        }
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
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
