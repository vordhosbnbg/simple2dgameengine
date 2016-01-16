#include <string>
#include "SDL.h"

using namespace std;
int main(int argc, char **argv) 
{
    int retVal = 1;
    if (SDL_Init(SDL_INIT_VIDEO) == 0) 
    {
        
        SDL_Window *win = SDL_CreateWindow("Hello World!", 100, 100, 480, 333, SDL_WINDOW_SHOWN);
        if (win)
        {
            SDL_Renderer *ren = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
            if (ren) 
            {
                string imagePath = ".\\res\\pictures\\solo.bmp";
                SDL_Surface *bmp = SDL_LoadBMP(imagePath.c_str());
                if (bmp) 
                {
                    SDL_Texture *tex = SDL_CreateTextureFromSurface(ren, bmp);
                    SDL_FreeSurface(bmp);
                    if (tex)
                    {
                        for (int i = 0; i < 10; ++i) {
                            //First clear the renderer
                            SDL_RenderClear(ren);
                            //Draw the texture
                            SDL_RenderCopy(ren, tex, NULL, NULL);
                            //Update the screen
                            SDL_RenderPresent(ren);
                            //Take a quick break after all that hard work
                            SDL_Delay(1000);
                        }
                        retVal = 0;
                    }
                    else 
                    {
                        // error
                    }
                    SDL_DestroyTexture(tex);

                }
                else 
                {
                    // error 
                }
                SDL_UnloadObject(bmp);
            }
            else
            {
                // error
            }
            SDL_DestroyRenderer(ren);
        }
        else
        {

        }
        SDL_DestroyWindow(win);
    }
    SDL_Quit();

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