#pragma once
#include "framework.h"
#include "WinAPIClass.h"
#define MAX_LOADSTRING 100

// static : 클래스 객체가 아닌, 클래스 자체에 포함되는 변수나 메서드를 표시하는 한정자.
// 정적 : 프로그램이 시작하면 생성, 프로그램이 종료돠면 해제.

// 도형의 색깔 설정
// - 도형의 선 색깔 : HPEN
// - 도형의 면 색깔 : HBRUSH

// ★★★★ 도형의 색깔을 설정하는 방법
// 1. 원하는 색의 펜, 브러쉬 생성
// 2. 생성한 펜, 브러쉬 선택...
// 3. 도형 그리기!
// 4. 기존에 사용하던 펜, 브러쉬 선택.
// 5. 생성했던 펜, 브러쉬 해제

class WinApp
{
private:
	static WinApp* instance;
private:
	int index;
	COLORREF color;

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

