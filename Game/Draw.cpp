#include "Draw.h"

void Draw::ReadFile()
{
	string xy;
	bool t = true;
	ifstream file;
	short d = 0, q = 0;
	file.open("Map.txt");
	file >> xy;
	for (int i = 0; i < xy.size(); i++)
	{
		if (xy[i] != '#' && t == true)
		{
			d++;
		}
		if (xy[i] == '#' && t == true)
		{
			d++;
		}
		if (xy[i] == '#')
		{
			q++;
			t = false;
		}
	}
	char** mas = new char* [q];
	for (int i = 0; i < q; i++)
	{
		mas[i] = new char[d];
	}
	file.seekg(0, ios::beg);
	file.clear();
	for (int i = 0; i < q; i++)
		for (int j = 0; j < d; j++)
			file >> mas[i][j];
	y = d - 1;
	x = q;
	map = new char* [x];
	for (int i = 0; i < x; i++)
	{
		map[i] = new char[y];
	}
	for (int i = 0, a = 0; i < q; i++)
	{
		for (int j = 0, k = 0; j < d; j++)
		{
			if (mas[i][j] != '#')
			{
				map[i][j] = mas[i][j];
			}
		}
	}
	for (int i = 0; i < q; i++)
	{
		delete[]mas[i];
	}
	delete[]mas;
	file.close();
}

void Draw::Show()
{
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			if (map[i][j] == '1')
			{
				SetConsoleTextAttribute(h, 8);
				cout << char(219);
			}
			if (map[i][j] == '0')
			{
				SetConsoleTextAttribute(h, BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_BLUE | BACKGROUND_INTENSITY);
				cout << " ";
				SetConsoleTextAttribute(h, 6);
			}
		}
		cout << endl;
	}
}
bool Draw::Check(short xx, short yy)
{
	if (map[yy][xx] == '1')
		return false;
	return true;
}
