#include "WinApp.h"

// ★★★★ 클래스의 static 변수는 소스 파일에서 반드시 정의 해야한다!
WinApp* WinApp::instance = nullptr;

LRESULT WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    return WinApp::GetInstance()->WndProc(hWnd, message, wParam, lParam);
}


WinApp* WinApp::GetInstance()
{
    return instance;
}

ATOM WinApp::RegisterWindowClass(HINSTANCE hInstance)
{
    hInst = hInstance;

    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_WINAPICLASS, szWindowClass, MAX_LOADSTRING);

    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc = ::WndProc; // 전역 함수의 주소'만' 가능.
    wcex.cbClsExtra = 0;
    wcex.cbWndExtra = 0;
    wcex.hInstance = hInstance;
    wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_WINAPICLASS));
    wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    wcex.lpszMenuName = MAKEINTRESOURCEW(IDC_WINAPICLASS);
    wcex.lpszClassName = szWindowClass;
    wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

BOOL WinApp::CreateMainWindow(int nCmdShow)
{
    hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInst, nullptr);

    if (!hWnd)
    {
        return FALSE;
    }

    ShowWindow(hWnd, nCmdShow);
    UpdateWindow(hWnd);

    return TRUE;
}

int WinApp::MessageLoop()
{
    // MSG : 메시지 구조체
    MSG msg;

    // GetMessage() : 메시지 큐에서 메시지를 가져오는 함수.

    
    // 기본 메시지 루프입니다:
    while (GetMessage(&msg, nullptr, 0, 0))
    {
        // TranslateMessage()
        // 메세지에 세부적인 정보를 추가하는 함수.
        // 세부 정보는 WPARAM, LPARAM에 들어감
        TranslateMessage(&msg);
        // 메세지 : 키보드 입력
        // 세부정보 : A키, 두번 입력 등등...

        // 메세지 처리 함수로 메세지를 보냄.(메세지 처리 함수 호출!)
        DispatchMessage(&msg);
        
    }

    return (int)msg.wParam;
}

LRESULT WinApp::WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {

        // WM_CREATE : 윈도우를 생성했을 때 발생하는 메세지.
        // (일반적으로 무언가를 초기화할 때 사용)
        case WM_CREATE:
            {
                text = nullptr;
            }
            break;
        // WM_LBUTTONDOWN : 마우스 왼쪽 버튼을 눌렀을 때 발생하는 메세지.
        case WM_LBUTTONDOWN:
            {
                //// "마우스를 클릭했습니다!" 텍스트 출력! 
                #pragma region 기존 코드
                
                                //// 1. 출력 영역을 가져오기!
                                //HDC hdc = GetDC(hWnd);

                                //const TCHAR* text = _T("마우스를 클릭했습니다!");
                                //TextOut(hdc, 0, 0, text, _tcslen(text));

                                //ReleaseDC(hWnd, hdc);
                #pragma endregion

                #pragma region InvalidateRect
                                const TCHAR* text = _T("마우스를 클릭했습니다!");
                                int length = _tcslen(text) + 1;
                                this->text = new TCHAR[length];
                                _tcscpy_s(this->text, length, text);

                                // InvalidateRect()
                                // Invalidate : 무효화하다!
                                // 직사각형 영역을 무효화하는 함수!(= 다시 그린다)

                                // InvalidateRect([윈도우 핸들], [직사각형 영역], [지우기 여부])
                                // [직사각형 영역] 
                                // : NULL일 경우, 윈도우 전체를 무효화 영역으로 설정.
                                InvalidateRect(hWnd, NULL, TRUE);
                #pragma endregion
            }
            break;
        case WM_COMMAND:
            {
                int wmId = LOWORD(wParam);
                // 메뉴 선택을 구문 분석합니다:
                switch (wmId)
                {
                    case IDM_ABOUT:
                        // DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
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
                // HDC : 출력 영역 핸들.
                HDC hdc = BeginPaint(hWnd, &ps);
                
                // TODO: 여기에 hdc를 사용하는 그리기 코드를 추가합니다...
                /*  if (text != nullptr)
                {
                    TextOut(hdc, 0, 0, text, _tcslen(text));
                }*/

                #pragma region _TextOut
                // TextOut() : 텍스트를 출력하는 함수
                // TextOut([출력 영역], x, y, [문자열], [문자열 길이])
                // TextOut(hdc, 0, 0, text, _tcslen(text));
#pragma endregion

                #pragma region _DrawText
                            //// DrawText([출력 영역, [문자열], [문자열 길이]
                            ////          [직사각형 영역], [스타일])

                            //// RECT : 직사각형의 정보를 저장하는 구조체
                            //RECT rect = { 0, 0, 50, 50 };
                            //DrawText(hdc, text, _tcslen(text), &rect, DT_LEFT);
            #pragma endregion

                // 도형 출력!
                // Rectangle() : 직사각형을 그리는 함수.
                // Rectangle(hdc, 100, 100, 800, 500);

                // Ellipse() : 원을 그리는 함수
                // Ellipse 타원
                // Ellipse(hdc, 100, 100, 800, 500);

                // 선 그리기
                // MoveToEx() : 시작점을 설정하는 함수.
                // LineTo() : 시작점에서 설정한 좌표까지 선을 그리는 함수.
                /*MoveToEx(hdc, 0, 0, NULL);
                LineTo(hdc, 500, 400);*/

                // 다각형 그리기.
                // Polygon([출력 영역], [POINT 배열], [배열의 길이])
                /*POINT pointArr[] = { {250, 0}, {0,500}, {500,500} };
                Polygon(hdc, pointArr, 3);*/

                // 별 그리기
                POINT pointArr[] = { { 250, 0 },{400,450}, { 0,100 }, { 500,100 }, {100,450} };
                Polygon(hdc, pointArr, 5);

                EndPaint(hWnd, &ps);
            }
            break;
        case WM_DESTROY:
            {
                if (text != nullptr)
                {
                    delete[] text;
                    text = nullptr;
                }

                PostQuitMessage(0);
            }
            
            break;
        default:
            return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

WinApp::WinApp()
{
    // 첫번째로 생성된 생성자가 instance에 들어감!
    if (!instance)
        instance = this;
}
