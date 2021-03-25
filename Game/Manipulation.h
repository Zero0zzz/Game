#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <windows.h>
#include <fstream>
#include <conio.h>
#include "Draw.h"
using namespace std;
class Manipulation
{
	short x, y;
	short px, py; // предыдущия кордината
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	Draw m;
public:
	Manipulation();
	void Coord();
	short GetXCoord() const ;
	short GetYCoord() const ;
	short GetPXCoord() const ;
	short GetPYCoord() const ;
	HANDLE GetHandle() const ;
	void Print();
};

