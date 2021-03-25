#pragma once
#include "Manipulation.h"
#include <iostream>
#include <windows.h>
using namespace std;

class Shot
{
	short x_shot, y_shot;

	Manipulation m;
public:
	Shot();

	//void show() const;

	short GetShotX()const;
	short GetShotY()const;
};

