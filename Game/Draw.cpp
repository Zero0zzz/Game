#include "Draw.h"
#include <iostream>
#include <windows.h>
#include <conio.h>
#define _CRT_SECURE_NO_WARNINGS
using namespace std;

void Draw::Create_file()
{
	char arr[1596];
	FILE* file;
	fopen_s(&file, "Map.txt", "r");
	fgets(arr, 1596, file);
	map = arr;
	show();
}

void Draw::show()const
{//
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	for (int i = 0; i < 1596; i++)
	{
		if (map[i] == '#')
		{
			i++;
			cout << endl;
		}
		if (map[i] == '1')
		{
			cout << char(219);
		}
		if (map[i] == '2')
		{
			SetConsoleTextAttribute(h, 4);
			cout << char(219);
			SetConsoleTextAttribute(h, 7);
		}
		if (map[i] == '0')
		{
			cout << char(177);
		}
	}
}

void Draw::key() const
{
	if (_kbhit()) {
		switch (_getch()) {
		case 'W': break;
		case 'w': break;
		case 'A': break;
		case 'a': break;
		}
	}
}

void Draw::go(char str) const
{
	if (str == ('W' || 'w')) {

	}
}

