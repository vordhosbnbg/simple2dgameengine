#include <Windows.h>

LRESULT CALLBACK MessageProcedure(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam) 
{
    return 0;
}


LRESULT CALLBACK WndProcedure(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam)
{
    switch (Msg)
    {
    case WM_DESTROY:
        PostQuitMessage(WM_QUIT);
        break;
    default:
        return DefWindowProc(hWnd, Msg, wParam, lParam);
    }
    return 0;
}

LPCTSTR ClsName = L"NeuralNetTester";
LPCTSTR WndName = L"NeuralNet Tester";

INT WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
    LPSTR lpCmdLine, int nCmdShow) 
{
    INT retVal = 1;
    HWND hWnd;
    MSG Msg;
    WNDCLASSEX WndClsEx;
    WndClsEx.cbSize = sizeof(WNDCLASSEX);
    WndClsEx.style = CS_HREDRAW | CS_VREDRAW;
    WndClsEx.lpfnWndProc = WndProcedure;
    WndClsEx.cbClsExtra = 0;
    WndClsEx.cbWndExtra = 0;
    WndClsEx.hIcon = LoadIcon(NULL, IDI_APPLICATION);
    WndClsEx.hIconSm = LoadIcon(NULL, IDI_APPLICATION);
    WndClsEx.hCursor = LoadCursor(NULL, IDC_ARROW);
    WndClsEx.hbrBackground = (HBRUSH)GetStockObject(DKGRAY_BRUSH);
    WndClsEx.lpszMenuName = NULL;
    WndClsEx.lpszClassName = ClsName;
    WndClsEx.hInstance = hInstance;

    RegisterClassEx(&WndClsEx);
    // Create the window object
    hWnd = CreateWindow(ClsName,
        WndName,
        WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT,
        CW_USEDEFAULT,
        CW_USEDEFAULT,
        CW_USEDEFAULT,
        NULL,
        NULL,
        hInstance,
        NULL);

    if (hWnd) 
    {
        // Display the window to the user
        ShowWindow(hWnd, SW_SHOWNORMAL);
        UpdateWindow(hWnd);

        // Decode and treat the messages
        // as long as the application is running
        while (GetMessage(&Msg, NULL, 0, 0))
        {
            TranslateMessage(&Msg);
            DispatchMessage(&Msg);
        }

        retVal = Msg.wParam;
    }

    return retVal;
}