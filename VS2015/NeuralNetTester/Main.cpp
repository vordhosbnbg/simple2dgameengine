#include <string>
#include "SDL.h"
#include "GraphicsDriver.h"
#include "GameEngine.h"
#include "Nanobot.h"
#include "Asteroid.h"

using namespace std;
int main(int argc, char **argv) 
{
    int retVal = 1;
    GameEngine engine;
    shared_ptr<Nanobot> bot1 = make_shared<Nanobot>();
    shared_ptr<Nanobot> bot2 = make_shared<Nanobot>();
    shared_ptr<Nanobot> bot3 = make_shared<Nanobot>();
    shared_ptr<Nanobot> bot4 = make_shared<Nanobot>();
    shared_ptr<Nanobot> bot5 = make_shared<Nanobot>();
    shared_ptr<Nanobot> bot6 = make_shared<Nanobot>();
    shared_ptr<Nanobot> bot7 = make_shared<Nanobot>();
    shared_ptr<Asteroid> rock1 = make_shared<Asteroid>();
    engine.StartEngine();
    engine.AddGameObject(bot1);
    engine.AddGameObject(bot2);
    engine.AddGameObject(bot3);
    engine.AddGameObject(bot4);
    engine.AddGameObject(bot5);
    engine.AddGameObject(bot6);
    engine.AddGameObject(bot7);
    engine.AddGameObject(rock1);
    bot1->SetPosition(Vector2D(200, 200));
    bot1->SetDirection(Vector2D(15, -4));
    bot2->SetPosition(Vector2D(300, 500));
    bot2->SetDirection(Vector2D(100, 120));
    bot3->SetPosition(Vector2D(500, 100));
    bot3->SetDirection(Vector2D(12, 3));
    bot4->SetPosition(Vector2D(300, 800));
    bot4->SetDirection(Vector2D(1, 334));
    bot5->SetPosition(Vector2D(400, 700));
    bot5->SetDirection(Vector2D(-1, -2));
    bot6->SetPosition(Vector2D(500, 100));
    bot6->SetDirection(Vector2D(1, -2.5));
    bot7->SetPosition(Vector2D(600, 200));
    bot7->SetDirection(Vector2D(-1, -1.5));
    rock1->SetPosition(Vector2D(400, 200));
    bot1->StartMovement();
    bot2->StartMovement();
    bot3->StartMovement();
    bot4->StartMovement();
    bot5->StartMovement();
    bot6->StartMovement();
    bot7->StartMovement();
    Sleep(4000);
    bot1->StopMovement();
    bot2->StopMovement();
    bot3->StopMovement();
    bot4->StopMovement();
    bot5->StopMovement();
    bot6->StopMovement();
    bot7->StopMovement();
    bot1->StartMining();
    bot2->StartMining();
    bot3->StartMining();
    bot4->StartMining();
    bot5->StartMining();
    bot6->StartMining();
    bot7->StartMining();
    Sleep(5000);
    bot1->StopMining();
    bot2->StopMining();
    bot3->StopMining();
    bot4->StopMining();
    bot5->StopMining();
    bot6->StopMining();
    bot7->StopMining();
    Sleep(5000);
    return retVal;
}


//#include <Windows.h>
//
//LRESULT CALLBACK MessageProcedure(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam) 
//{
//    return 0;
//}
//
//
//LRESULT CALLBACK WndProcedure(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam)
//{
//    switch (Msg)
//    {
//    case WM_DESTROY:
//        PostQuitMessage(WM_QUIT);
//        break;
//    default:
//        return DefWindowProc(hWnd, Msg, wParam, lParam);
//    }
//    return 0;
//}
//
//LPCTSTR ClsName = L"NeuralNetTester";
//LPCTSTR WndName = L"NeuralNet Tester";
//
//INT WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
//    LPSTR lpCmdLine, int nCmdShow) 
//{
//    INT retVal = 1;
//    HWND hWnd;
//    MSG Msg;
//    WNDCLASSEX WndClsEx;
//    WndClsEx.cbSize = sizeof(WNDCLASSEX);
//    WndClsEx.style = CS_HREDRAW | CS_VREDRAW;
//    WndClsEx.lpfnWndProc = WndProcedure;
//    WndClsEx.cbClsExtra = 0;
//    WndClsEx.cbWndExtra = 0;
//    WndClsEx.hIcon = LoadIcon(NULL, IDI_APPLICATION);
//    WndClsEx.hIconSm = LoadIcon(NULL, IDI_APPLICATION);
//    WndClsEx.hCursor = LoadCursor(NULL, IDC_ARROW);
//    WndClsEx.hbrBackground = (HBRUSH)GetStockObject(DKGRAY_BRUSH);
//    WndClsEx.lpszMenuName = NULL;
//    WndClsEx.lpszClassName = ClsName;
//    WndClsEx.hInstance = hInstance;
//
//    RegisterClassEx(&WndClsEx);
//    // Create the window object
//    hWnd = CreateWindow(ClsName,
//        WndName,
//        WS_OVERLAPPEDWINDOW,
//        CW_USEDEFAULT,
//        CW_USEDEFAULT,
//        CW_USEDEFAULT,
//        CW_USEDEFAULT,
//        NULL,
//        NULL,
//        hInstance,
//        NULL);
//
//    if (hWnd) 
//    {
//        // Display the window to the user
//        ShowWindow(hWnd, SW_SHOWNORMAL);
//        UpdateWindow(hWnd);
//
//        // Decode and treat the messages
//        // as long as the application is running
//        while (GetMessage(&Msg, NULL, 0, 0))
//        {
//            TranslateMessage(&Msg);
//            DispatchMessage(&Msg);
//        }
//
//        retVal = Msg.wParam;
//    }
//
//    return retVal;
//}