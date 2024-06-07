// dllmain.cpp : Определяет точку входа для приложения DLL.
#include "pch.h"
#include <windows.h>
#include <cstring>

extern "C" __declspec(dllexport) bool CheckCharsInString(const char* str, const char* chars) {
	while (*chars) {
		if (!strchr(str, *chars)) {
			return false;
		}
		chars++;
	}
	return true;
}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD  ul_reason_for_call, LPVOID lpReserved) {
	return TRUE;
}