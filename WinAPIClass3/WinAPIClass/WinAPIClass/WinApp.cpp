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
                index = 0;
                color = RGB(255, 0, 0);
                
            }
            break;
        case WM_LBUTTONDOWN:
            {
                index++;
                if (index >= 3)
                    index = 0;

                switch (index)
                {
                    case 0:
                        color = RGB(255, 0, 0);
                        break;
                    case 1:
                        color = RGB(255,255, 0);
                        break;
                    case 2:
                        color = RGB(0,255, 0);
                        break;
                }
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
                        // DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBO X), hWnd, About);
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
                #pragma region 도형 색상 변경
                        //// TODO: 여기에 hdc를 사용하는 그리기 코드를 추가합니다...

                        //// 1. 원하는 색의 펜, 브러쉬 생성
                        //// CreatePen() : 펜을 생성하는 함수.
                        //// CreatePen([펜 스타일], [선 두께], [색깔(RGB)])
                        //                
                        //// CreateSolidBrush() : 브러쉬를 생성하는 함수
                        //// CreateSolidBrush([색깔(RGB)])
                        //
                        //HPEN hPen = CreatePen(PS_SOLID, 2, RGB(255, 255, 0));

                        //HBRUSH hBrush = CreateSolidBrush(RGB(0, 255, 0));


                        //// 2. 생성한 펜, 브러쉬 선택...(Select).
                        //// SelectObject()
                        //// 반환 데이터 : 기존에 사용하던 그래픽 오브젝트.
                        ////  : 그래픽 오브젝트(펜, 브러쉬 등)를 선택하는 함수.
                        //// (+ 기존에 사용하던 펜, 브러쉬를 저장.)
                        //HPEN oldPen = (HPEN)SelectObject(hdc, hPen);
                        //HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, hBrush);
                        //
                        //// 3. 도형 그리기!
                        //Rectangle(hdc, 100, 100, 500, 200);
                        //
                        //// 4. 기존에 사용하던 펜, 브러쉬 선택.
                        //SelectObject(hdc, oldPen);
                        //SelectObject(hdc, oldBrush);
                        //
                        //// 5. 생성했던 펜, 브러쉬 해제
                        //// DeleteObject([그래픽 오브젝트])
                        //// : 그래픽 오브젝트를 해제하는 함수.
                        //DeleteObject(hPen);
                        //DeleteObject(hBrush);
        #pragma endregion

                // 마우스 왼쪽 버튼을 클릭하면 
                // 빨간색 - 노란색 - 초록색으로 순으로
                // 색깔이 변경되는 원 그리기.
                // (처음 색깔은 빨간색으로 시작!)


                
                HBRUSH hBrush = CreateSolidBrush(color);
                HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, hBrush);
               
                Ellipse(hdc, 200, 200, 600, 600);

                SelectObject(hdc, oldBrush);

                DeleteObject(hBrush);


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
