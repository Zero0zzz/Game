#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <windows.h>
#include <fstream>
#include <conio.h>
#include <vector>
using namespace std;
class Draw
{
protected:
	char** map;
	short x, y;
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
public:
	Draw() = default;
	void ReadFile();
	void Show();
	bool Check(short, short);

};

