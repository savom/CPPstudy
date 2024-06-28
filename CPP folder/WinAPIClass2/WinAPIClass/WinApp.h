#pragma once
#include "framework.h"
#include "WinAPIClass.h"
#define MAX_LOADSTRING 100

// static : 클래스 객체가 아닌, 클래스 자체에 포함되는 변수나 메서드를 표시하는 한정자.
// 정적 : 프로그램이 시작하면 생성, 프로그램이 종료돠면 해제.

// 출력 영역(Device Context, DC)
// : 윈도우에서 텍스트/이미지 등을 출력할 수 있는 영역.
// 윈도우에 무언가르 출력하려면 '반드시' 출력 영역(DC)가 필요하다.

// 윈도우에서 출력 영역을 가져오는 함수/ 해제하는 함수.
// - GetDC(), ReleaseDC() : WM_PAINT 이외의 메세지에서 사용.
// - BeginPaint(), EndPaint() : WM_PAINT에서 사용.

// 출력 영역을 가져왔을 경우, 반드시 '해제'해야 한다!

// TCHAR 
// : 프로젝트 설정에 따라, char <-> WCHAR로 변경되는 문자 데이터 형식.

// <문자열 함수>
// - strlen, strcpy_s, strcat_s, strcmp

// WCHAR
// -wcslen, wcscpy_s, wcscat_s, wcscmp

// TCHAR
// - _tcslen, _tcscpy_s, _tcscat_s, _tcscmp

// 윈도우는 여러 상황에서 다시 그린다.(윈도우 출력 영역을 새로 그림)
// - 무효화 영역이 발생했을 떄
// - 윈도우의 크기가 변경되었을 때

// ★★★★★
// 윈도우가 주기적으로 다시 그려지기 떄문에
// WM_PAINT 외의 메세지에서 무언가를 출력하는 것은 바람직하지 않음!

// 출력할 텍스트/이미지를 연산 -> WM_PAINT 외
// 텍스트/이미지 등 무언가를 출력하는 코드 -> WM_PAINT

class WinApp
{
private:
	static WinApp* instance;

public:
	static WinApp* GetInstance();

private:
	HINSTANCE hInst; 
	HWND hWnd;
	TCHAR szTitle[MAX_LOADSTRING];   // (T)CHAR : T는 컴파일 환경에 따라 문자열을 처리할 수 있음.
	TCHAR szWindowClass[MAX_LOADSTRING];            
	
private:
	TCHAR* text;



public:
	ATOM                RegisterWindowClass(HINSTANCE hInstance);
	BOOL                CreateMainWindow(int nCmdShow);
	int					MessageLoop();
	LRESULT CALLBACK    WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
	
public:
	WinApp();
	~WinApp() = default;

};

