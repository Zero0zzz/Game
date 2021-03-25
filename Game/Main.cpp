#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <windows.h>
#include "Draw.h"
#include "Manipulation.h"

typedef BOOL(WINAPI* SETCONSOLEFONT)(HANDLE, DWORD);
SETCONSOLEFONT SetConsoleFont;

using namespace std;
int main()
{

	system("MODE CON COLS=100 LINES=122");

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

	CONSOLE_FONT_INFOEX cfi;
	cfi.cbSize = sizeof cfi;
	cfi.nFont = 0;
	cfi.dwFontSize.X = 15;
	cfi.dwFontSize.Y = 25;
	cfi.FontFamily = FF_DONTCARE;
	cfi.FontWeight = FW_NORMAL;
	//wcscpy(cfi.FaceName, L"Lucida Console");
	wcscpy(cfi.FaceName, L"Lucida Console");
	SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);

	Draw dr;
	Manipulation w;

	dr.ReadFile(); // считывание с файла 
	dr.Show(); // отрисовка 
	while (1)
	{
		w.Print();
	}
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
