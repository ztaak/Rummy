#pragma once


#include <string>
#include <vector>

const int NUM_OF_BRICKS_IN_GAME = 104;

const int BRICK_WIDTH = 60;
const int BRICK_HEIGHT = 80;

const int HOLDER_WIDTH = 8;
const int HOLDER_HEIGHT = 2;
const int HOLDER_CAPACITY =  HOLDER_WIDTH * HOLDER_HEIGHT;

const int GRID_WIDTH = 15;
const int GRID_HEIGHT = 7;
const int GRID_CAPACITY = GRID_WIDTH * GRID_HEIGHT;
 

inline bool is_point_in_bound(int x1, int y1, int x2, int y2, int w, int h){
	if(x1 >= x2 && x1 <= x2 + w &&
		y1 >= y2 && y1 <= y2 + h) 
		return true;
	return false;
}
































