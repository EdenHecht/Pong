#pragma once
#include "Board.h"
#include "Point.h"
#include <iostream>
using namespace std;

class Screen {
	//The ball's limits change according to the players disqualifications
	static int max_left;
	static int max_right;
public:
	enum { MAX_X = 76, MAX_Y = 24 };
	static bool isOn_Y_Edge(const Point& p);
	static bool isOn_X_Edge(const Point& p) {
		return p.y == 4 || p.y == MAX_Y;
	}
	void draw();
	
	void check_max_left();
	void check_max_right();
};
