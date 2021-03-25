#include "Shot.h"

Shot::Shot()
{
	if (m.GetXCoord() - 1 == m.GetPXCoord()) {
		x_shot = m.GetXCoord() + 1;
	}
	else if (m.GetXCoord() + 1 == m.GetPXCoord()) {
		x_shot = m.GetXCoord() - 1;
	}

	if (m.GetYCoord() + 1 == m.GetPYCoord()) {
		y_shot = m.GetYCoord() - 1;
	}
	else if (m.GetYCoord() - 1 == m.GetPYCoord()) {
		y_shot = m.GetYCoord() + 1;
	}
}

//void Shot::show() const
//{
//	SetConsoleCursorPosition(m.GetHandle(), { x_shot , y_shot });
//	cout << ".";
//}

short Shot::GetShotX() const
{
	return x_shot;
}

short Shot::GetShotY() const
{
	return y_shot;
}

