#include <windows.h>
#include <stdio.h>
#include <iostream>
#include <conio.h>
#include <string>
#include <fstream>
#include <float.h>
#include "stdafx.h"

using namespace std;

DWORD WINAPI LoopFunction(LPVOID lpParam)
{
	BYTE skill[] = { 0x688, 0x1F8, 0x3A8 };
	BYTE unbesiegbar[] = { 0x688, 0x1F8, 0x398 };
	BYTE dmg1[] = { 0x688, 0x1F8, 0x1DE };
	BYTE dmg2[] = { 0x688, 0x1F8, 0x1DC };
	BYTE speed[] = { 0x688, 0x1F8, 0x93C };

	bool HackOn = false;

	HANDLE TClient = GetCurrentProcess();

	while (1) {
		if (GetAsyncKeyState(VK_F12) & 0x80000) {

			if (HackOn == true) {
				WriteProcessMemory(TClient, (void*)(0x05C888C), &unbesiegbar, (DWORD)65536, 0);

				HackOn = false;

			}
			else if (HackOn == false) {
				WriteProcessMemory(TClient, (void*)(0x05C888C), &unbesiegbar, (DWORD)0, 0);

				HackOn = true;
			}

		}

	}
	//some CPU relief
	Sleep(200);
	return 0;
}



BOOL WINAPI DllMain(HINSTANCE hModule, DWORD dwAttached, LPVOID lpvReserved)
{
	if (dwAttached == DLL_PROCESS_ATTACH) {
		CreateThread(NULL, 0, &LoopFunction, NULL, 0, NULL);
	}
	return 1;
}

