#include "Screen.h"

int Screen::max_left = 4;
int Screen::max_right = 76;

void Screen:: draw()
{


	int i;
	setColor(COLOR::TEAL_TEXT);

	for (i = 0; i < MAX_X + 5; i++)
	{
		cout << "\xB1";
	}
	cout << endl;

	for (i = 1; i < MAX_Y+1; i++)
	{
		cout << "\xB1" << endl;
	}

	gotoxy(MAX_X+4, 1);

	for (i = 1; i < MAX_Y+1; i++)
	{
		cout << "\xB1";
		gotoxy(MAX_X+4, i + 1);
	}

	gotoxy(0, MAX_Y+1);

	for (i = 0; i < MAX_X + 5; i++)
	{
		cout << "\xB1";
	}
	cout << endl;

	gotoxy(1, 3);

	for ( i = 1; i < MAX_X+4; i++)
	{
		cout << "\xCD";
	}
	gotoxy(MAX_X / 2 - 7, 2);
	setColor(COLOR::YELLOW_TEXT);
	cout << "PONG AND TETRIS";
}

//sheck if the ball is on the right or left wall
bool Screen:: isOn_Y_Edge(const Point& p) {
	return p.x == max_left || p.x == max_right;
}

void Screen:: check_max_left()
{
	max_left++;
}
void Screen:: check_max_right()
{
	max_right--;
}