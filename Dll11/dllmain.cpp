// dllmain.cpp : Definiert den Einstiegspunkt für die DLL-Anwendung.
#include "stdafx.h"

#include <windows.h>
#include <stdio.h>
#include <iostream>
#include <conio.h>
#include <string>
#include <fstream>
#include <float.h>

using namespace std;

DWORD WINAPI LoopFunction(LPVOID lpParam)
{
	BYTE unbesiegbar[] = { 0x688, 0x1F8, 0x398 };
	

	bool HackOn = false;

	int ficken = 65536;

	HANDLE TClient = GetCurrentProcess();

	while (1) {
		if (GetKeyState(VK_F12)) {

			if (HackOn == true) {
				WriteProcessMemory(TClient, (void*)(0x05C888C), &unbesiegbar, sizeof(ficken), NULL);

				HackOn = false;

			}
			else if (HackOn == false) {
				WriteProcessMemory(TClient, (void*)(0x05C888C), &unbesiegbar, 0, NULL);

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
		MessageBox(0, (LPCSTR)"Hello from notepad!", "notepad", MB_OK);

	}
	return 1;
}


