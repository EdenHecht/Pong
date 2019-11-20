#include "Game.h"
bool Game::isOver = false;

void Game::run() {

	DeadBoards left,right;

	hideConsoleCursor();

	//place the board according to instructions
	Board board1({ BOARD_LEFT_X,BOARD_LEFT_UP,'#' }, { BOARD_LEFT_X, BOARD_LEFT_DOWN, '#' }, { "qa" });
	Board board2({ BOARD_RIGHT_X,BOARD_RIGHT_UP,'#' }, { BOARD_RIGHT_X,BOARD_RIGHT_DOWN,'#' }, { "pl" });
	Ball ball({ BALL_X ,BALL_Y, 'O' });
	Screen s;
	s.draw();
	board1.draw();
	board2.draw();

	KeyboardManager kbManager;
	kbManager.registerKbListener(&board1);
	kbManager.registerKbListener(&board2);

	bool missedleft = false;
	bool missedright = false;

	while (!isOver)
	{

		while (!missedleft && !missedright)
		{
			for (int i = 0; i < 10; ++i)//Get users keyboard input
			{
				kbManager.handleKeyboard();
				Sleep(10);
			}

			ball.draw();

			//change ball direction if needed
			missedleft = board1.switchBallPosition(ball, missedleft);
			missedright = board2.switchBallPosition(ball, missedright);
			ball.move();

		}

		//if somebody missed the ball

		ball.ballReset();//stop the ball
		ball.Originalball(BALL_X ,BALL_Y);

		checkWhoMissed(board1, board2, missedleft, missedright,s,left,right);

		missedleft = false;
		missedright = false;

	}
}

//When one player misses we need to check who missed
void Game::checkWhoMissed(Board& left, Board& right, bool flagLeft, bool flagRight, Screen& s, DeadBoards& deadBoardsLeft, DeadBoards& deadBoardsRight)
{
	//if the left player miss and it's less than 20 misses 
	if (flagLeft == true && left.getX() != 20 && right.getX() != 60)
	{
	
		//print the current dead board and restart the original positions 
		deadBoardsLeft.printDead(left);
		left.OriginalBoard(RESTART_X_LEFT_MISS, BOARD_LEFT_UP, BOARD_LEFT_DOWN);
		left.draw();
		s.check_max_left();
		right.erase();
		right.OriginalBoard(RESTART_X, BOARD_RIGHT_UP, BOARD_RIGHT_DOWN);
		right.draw();
	}

	//if the right player miss and it's less than 20 misses 
	else if (flagRight == true && right.getX() != 60 && left.getX() != 20)
	{
		//print the current dead board and restart the original positions 
		deadBoardsRight.printDead(right);
		right.OriginalBoard(RESTART_X_RIGHT_MISS, 11, 13);
		right.draw();
		s.check_max_right();
		left.erase();
		left.OriginalBoard(RESTART_X, 10, 12);
		left.draw();
	}
	else
	{
		isOver= true;
		system("cls");
	}
}

//print the menu
void Game::menu()
{

	char ch;

	gotoxy(MAX_X / 2, MAX_Y / 2);
	system("Color E");
	cout << "MENU\n";

	gotoxy(MAX_X / 3, (MAX_Y / 2) + 2);
	cout << "New game - press 1" << endl;
	gotoxy(MAX_X / 3, (MAX_Y / 2) + 3);
	cout << "Instructions and keys - press 8" << endl;
	gotoxy(MAX_X / 3, (MAX_Y / 2) + 4);
	cout << "Exit - press 9" << endl;

	ch = _getch();

	switch (ch)
	{
	case'1':
		system("cls");
		run();
		break;
	case '8':
		system("cls");
		Instructions();
		system("cls");
		run();
		break;
	case '9':
		isOver = true;
		break;
	};
}


void Game::Instructions() const
{
	char key;
	
	setColor(COLOR::RED_TEXT);
	cout << "Dear examiner!" << endl<<endl;

	setColor(COLOR::TEAL_TEXT);

	cout <<"Your goal is to hit the ball with the board." << endl <<
		"Once you miss the ball a copy of your board will appear at the edge of the wall" << endl <<
		"and the new position of the board will go 'up' by one," << endl << "making him one step closer to losing." <<
		"When you get to 20 disqualification you lose and the game will be over." << endl << endl;

	setColor(COLOR::WHITE_TEXT);

		cout << "KEYBOARD:" << endl;
	
		setColor(COLOR::GRAY_TEXT);

		cout<< "Right player: up - p/P" << endl << "	    down - l/L" << endl;

		cout << "Left player: up - q/Q" << endl << "	    down - a/A" << endl << endl;
		
		setColor(COLOR::PINK_TEXT);
		cout << "Good Luck" << endl << "WE HAVE FAITH IN YOU!" << endl << endl << endl;
		
		setColor(COLOR::YELLOW_TEXT);

		cout <<"press 0 and enter to return to start playing" << endl;

	cin >> key;
	return;
}
