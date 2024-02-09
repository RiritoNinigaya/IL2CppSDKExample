// dllmain.cpp : Defines the entry point for the DLL application.
#include <Windows.h>
#include <xstring>
#include <iostream>
#include "il2cppsdk.h"
using namespace std;

void Shutdown() {
    IL2CPPSDK::Initialize();
}
BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
        CreateThread(0, 0, reinterpret_cast<LPTHREAD_START_ROUTINE>(Shutdown), 0, 0, 0);
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}

