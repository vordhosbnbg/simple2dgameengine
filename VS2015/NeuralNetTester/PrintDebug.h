#ifndef PRINT_DEBUG_H
#define PRINT_DEBUG_H
#ifdef _DEBUG
#define PrintDebug(x) OutputDebugStringA(x)
#else
#define PrintDebug(x) 
#endif // DEBUG


#endif // PRINT_DEBUG_H
