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
        case WM_CREATE:
            {
                rect = { 0,0,0,0 };
            }
        case WM_LBUTTONDOWN:
            {
                isDrag = true;
               // 시작 지점, 끝 지점 모두 마우스 위치로 설정!
                int x = LOWORD(lParam);
                int y = HIWORD(lParam);

                rect.left = rect.right = x;
                rect.top = rect.bottom = y;

                InvalidateRect(hWnd, NULL, TRUE);
            }
            break;
        case WM_LBUTTONUP:
            {
                isDrag = false;
                int x = LOWORD(lParam);
                int y = HIWORD(lParam);

                rect.right = x;
                rect.bottom = y;

                InvalidateRect(hWnd, NULL, TRUE);
                
              
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
        case WM_MOUSEMOVE:
            {
                #pragma region 마우스 위치
                                // 마우스 위치 출력!
                                // lParam : 마우스 위치
                                // lParam(16바이트 정수)를
                                // 8바이트씩 나눠서 사용!
                                // LOWORD() : 낮은 자리 수 8바이트. x
                                // HIWORD() : 높은 자리 수 8바이트. y
                                /*int x = LOWORD(lParam);
                                int y = HIWORD(lParam);
                                HDC hdc = GetDC(hWnd);

                                TCHAR text[50] = { 0 };*/

                                // 출력(화면 출력x)
                                // 문자열 저장 공간에 '형식 문자열'을 출력(화면 출력x)하는 함수.
                                // 문자열 저장 공간에 정수나 실수 등등 문자열이 아닌 데이터를 넣고 싶을 때 사용!
                                /*_stprintf_s(text, 50, _T("마우스의 위치 : %d, %d"), x, y);

                                TextOut(hdc, 0, 0, text, _tcslen(text));

                                ReleaseDC(hWnd, hdc);*/
                #pragma endregion 

                // 마우스를 드래그 해서
                // 원 그리기!

                if (isDrag)
                {
                    int x = LOWORD(lParam);
                    int y = HIWORD(lParam);

                    rect.right = x;
                    rect.bottom = y;

                    InvalidateRect(hWnd, NULL, TRUE);
                }

                
            }
            break;
        case WM_PAINT:
            {
                PAINTSTRUCT ps;
                HDC hdc = BeginPaint(hWnd, &ps);
                
                Ellipse(hdc, rect.left, rect.top, rect.right, rect.bottom);



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

WinApp::WinApp()
{
    // 첫번째로 생성된 생성자가 instance에 들어감!
    if (!instance)
        instance = this;
}
