#include "Manipulation.h"
Manipulation::Manipulation()
{
	x = 10;
	y = 10;
	px = x;
	py = y;
	m.ReadFile();
}

void Manipulation::Coord()
{
	if (_kbhit()) {//управление
		switch (_getch()) {
		case 'W':
		case 'w':
			y--;
			break;
		case 'S':
		case 's':
			y++;
			break;
		case 'A':
		case 'a':
			x--;
			break;
		case 'D':
		case 'd':
			x++;
			break;
		case 'R':
		case 'r':
			exit(1);
			break;
		}
	}
	SetConsoleCursorPosition(h, { 90,10 });
	cout << x << " " << y;
}

short Manipulation::GetXCoord()
{
	return x;
}

short Manipulation::GetYCoord()
{
	return y;
}

short Manipulation::GetPXCoord()
{
	return px;
}

short Manipulation::GetPYCoord()
{
	return py;
}

void Manipulation::Print()
{
	SetConsoleCursorPosition(h, { GetPXCoord(),GetPYCoord() });
	SetConsoleTextAttribute(h, BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_BLUE | BACKGROUND_INTENSITY);
	cout << " ";
	px = x;
	py = y;
	Coord();
	if (m.Check(x, y) == 0)
	{
		x = px;
		y = py;
	}
	if (m.Check(x, y) == 1)
	{
		SetConsoleCursorPosition(h, { x,y });
		SetConsoleTextAttribute(h, 4);
		cout << char(219);
	}
	Sleep(10);
}
