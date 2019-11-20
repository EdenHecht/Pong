#pragma once
#include "Point.h"


class Ball {
	enum {UP_RIGHT,DOWN_RIGHT,UP_LEFT,DOWN_LEFT};
	Point location;
	int dir_x = -1;
	int dir_y =1;
public:
	Ball(Point p) : location(p) {}
	enum YDirection { DOWN, UP };
	void move();
	void draw()
	{
		location.draw();
	}
	int getY()const {
		return location.getY();
	}
	int getX()const {
		return location.getX();
	}
	void changeYDirection() {
		dir_y *= -1;
	}
	void changeXDirection() {
		dir_x *= -1;
	}
	Ball::YDirection getYDirection() const {
		return dir_y == 1 ? DOWN : UP;
	}
	void ballReset();

	void Originalball(int x, int y); 
	
};