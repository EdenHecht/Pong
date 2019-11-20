#pragma once
#include "Point.h"

// forward declaration
class Ball;

class Board {
	Point up, down;
	//We recive the keys as a string - the first key is the 'up' key
	//and the second is the 'down' key
	enum {kbUp, kbDown}; 
	const char* kbChars;
public:
	enum class BallPosition {MISSED, CENTER_HIT, CORNER_HIT, AWAY};
	Board(const Point& up1, const Point& down1,const char* keys) : up(up1), down(down1),kbChars(keys) {}
	void draw();
	void handleKey(char c);
	const char* getKbChars() {
		return kbChars;
	}
	int getX() {
		return up.getX();
	}
	int getUpY()const {
		return up.getY();
	}
	int getDownY()const {
		return down.getY();
	}
	//Once the player missed we want to move it back to the original
	//position and to move it one step closer to the middle of the screen
	void OriginalBoard(int key,int up1,int down1) {
		up.setBoard(key,up1);
		down.setBoard(key,down1);
	}

	void  setX();
	void erase();

	BallPosition checkBallPosition(const Ball& ball);
	bool switchBallPosition(Ball& ball,bool flag);
};