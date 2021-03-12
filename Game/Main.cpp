#include<iostream>
#include <windows.h>
#include"Draw.h"

typedef BOOL(WINAPI* SETCONSOLEFONT)(HANDLE, DWORD);
SETCONSOLEFONT SetConsoleFont;

using namespace std;
int main()
{
	system("mode con cols=75 lines=25");
	CONSOLE_FONT_INFO CFI;
	CONSOLE_FONT_INFO* pCFI = &CFI;

	GetCurrentConsoleFont(GetStdHandle(STD_OUTPUT_HANDLE), false, pCFI);

	HMODULE hmod = GetModuleHandleA("KERNEL32.DLL");
	SetConsoleFont = (SETCONSOLEFONT)
		GetProcAddress(hmod, "SetConsoleFont");


	for (int i = 0; i < 16; i++) {
		SetConsoleFont(GetStdHandle(STD_OUTPUT_HANDLE), i);
		GetCurrentConsoleFont(GetStdHandle(STD_OUTPUT_HANDLE), false, pCFI);

	}

	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD c;
	CONSOLE_CURSOR_INFO info2;
	info2.bVisible = false;
	info2.dwSize = 100;
	SetConsoleCursorInfo(h, &info2);

	HANDLE hin = GetStdHandle(STD_INPUT_HANDLE);
	SetConsoleMode(hin, ENABLE_MOUSE_INPUT | ENABLE_EXTENDED_FLAGS);
	INPUT_RECORD all_events;
	DWORD a;

	Draw dr;
	dr.Create_file();


	//123


	system("pause >> null");
}

/*
typedef BOOL(WINAPI* SETCONSOLEFONT)(HANDLE, DWORD);     // прототип недокументированый функции
SETCONSOLEFONT SetConsoleFont;


int main() {

	//Определимся со структурой CONSOLE_FONT_INFO
	CONSOLE_FONT_INFO CFI;
	CONSOLE_FONT_INFO* pCFI = &CFI;

	//Информация о шрифте- так, чтобы знать!
	GetCurrentConsoleFont(GetStdHandle(STD_OUTPUT_HANDLE), false, pCFI);

	HMODULE hmod = GetModuleHandleA("KERNEL32.DLL");
	SetConsoleFont = (SETCONSOLEFONT)GetProcAddress(hmod, "SetConsoleFont");

	for (int i = 0; i < 16; i++) {
		SetConsoleFont(GetStdHandle(STD_OUTPUT_HANDLE), i);
		GetCurrentConsoleFont(GetStdHandle(STD_OUTPUT_HANDLE), false, pCFI);
	}

}*/