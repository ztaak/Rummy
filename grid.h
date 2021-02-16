#pragma once 

#include "common.h"
#include <raylib.h>



extern void grid_init(int position_x, int position_y);
extern void grid_draw();

extern int grid_put(int brick_id, int mouse_x, int mouse_y);
extern int grid_take_out(int brick_id);































