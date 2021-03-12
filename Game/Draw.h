#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
class Draw
{
	string map;
public:
	Draw() = default;
	void Create_file();
	void show()const;
	void key()const;
	void go(char str) const;
};

