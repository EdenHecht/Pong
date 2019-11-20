#pragma once

#include "Board.h"
#include "KeyBoardManager.h"
#include "Ball.h"
#include "Screen.h"
#include "DeadBoards.h"
#include <conio.h>

class Game {
	enum{ MAX_X= 80, MAX_Y=25};
	enum {
		BOARD_RIGHT_X = 76, BOARD_LEFT_X = 4, BOARD_RIGHT_UP = 11, BOARD_RIGHT_DOWN = 13,
		BOARD_LEFT_UP = 10, BOARD_LEFT_DOWN = 12, BALL_X = 38, BALL_Y = 10, RESTART_X_LEFT_MISS = 1,
		RESTART_X_RIGHT_MISS = -1, RESTART_X = 0};

	static bool isOver;
	void Instructions() const;
public:

	void run();
	void checkWhoMissed(Board& left, Board& right, bool flagLeft, bool flagRight, Screen& s, DeadBoards& deadBoardsLeft, DeadBoards& deadBoardsRight);
	void menu();
};