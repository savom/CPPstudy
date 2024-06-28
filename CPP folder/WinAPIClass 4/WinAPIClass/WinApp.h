#pragma once
#include "framework.h"
#include "WinAPIClass.h"
#define MAX_LOADSTRING 100

// static : 클래스 객체가 아닌, 클래스 자체에 포함되는 변수나 메서드를 표시하는 한정자.
// 정적 : 프로그램이 시작하면 생성, 프로그램이 종료돠면 해제.

// 제어 메시지.
// 마우스, 키보드 관련 메시지.

// 마우스 메세지.
// WM_LBUTTONDOWN,
// WM_LBUTTONUP
// WM_RBUTTONDOWN,
// WM_RBUTTONUP
// WM_MOUSEMOVE : 마우스가 움직일 때 발생하는 메세지
// ....

class WinApp
{
private:
	static WinApp* instance;

private:
	RECT rect;
	bool isDrag;
public:
	static WinApp* GetInstance();

private:
	HINSTANCE hInst; 
	HWND hWnd;
	TCHAR szTitle[MAX_LOADSTRING];   // (T)CHAR : T는 컴파일 환경에 따라 문자열을 처리할 수 있음.
	TCHAR szWindowClass[MAX_LOADSTRING];            

public:
	ATOM                RegisterWindowClass(HINSTANCE hInstance);
	BOOL                CreateMainWindow(int nCmdShow);
	int					MessageLoop();
	LRESULT CALLBACK    WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
	
public:
	WinApp();
	~WinApp() = default;

};

