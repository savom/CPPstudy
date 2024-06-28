#pragma once
#include "framework.h"
#include "WinAPIClass.h"
#define MAX_LOADSTRING 100

// static : 클래스 객체가 아닌, 클래스 자체에 포함되는 변수나 메서드를 표시하는 한정자.
// 정적 : 프로그램이 시작하면 생성, 프로그램이 종료돠면 해제.

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

public:
	ATOM                RegisterWindowClass(HINSTANCE hInstance);
	BOOL                CreateMainWindow(int nCmdShow);
	int					MessageLoop();
	LRESULT CALLBACK    WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
	
public:
	WinApp();
	~WinApp() = default;

};

