#include "grid.h"
#include "brick.h"



static std::vector<int> bricks;
static int pos_x = 0;
static int pos_y = 0;
static int width = GRID_WIDTH * BRICK_WIDTH;
static int height = GRID_HEIGHT * BRICK_HEIGHT;



void grid_draw(){
	for(int y = 0; y < GRID_HEIGHT; ++y){
		for(int x = 0; x < GRID_WIDTH; ++x){
			DrawRectangleLines(x*BRICK_WIDTH, y*BRICK_HEIGHT, BRICK_WIDTH, BRICK_HEIGHT, BLACK);
		}
	}
}


void grid_init(int position_x, int position_y){
	pos_x = position_x;
	pos_y = position_y;
	bricks.resize(GRID_CAPACITY);
	std::fill(bricks.begin(), bricks.end(), -1);
}

int grid_take_out(int brick_id){
	for(int i = 0; i < GRID_CAPACITY; ++i){
		if(bricks[i] == -1 || bricks[i] != brick_id)
			continue;
		else{
			bricks[i] = -1;
			return brick_id;
		}
	}
	return -1;
}

int grid_put(int brick_id, int mouse_x, int mouse_y){
	if(!is_point_in_bound(mouse_x, mouse_y, pos_x, pos_y, width, height)){
		printf("CANNOT PUT OF BOUND OF GRID\n");	
	return -1;
	}

	int local_x = mouse_x - pos_x;
	int local_y = mouse_y - pos_y;
	
	int tile_x = local_x / BRICK_WIDTH;
	int tile_y = local_y / BRICK_HEIGHT;
	
	printf("MOUSE(%ix%i), LOCAL(%ix%i), TILE(%ix%i)\n", 
			mouse_x, mouse_y, local_x, local_y, tile_x, tile_y);

	if(bricks[(tile_y * GRID_WIDTH) + tile_x] == -1){
		bricks[(tile_y * GRID_WIDTH) + tile_x] = brick_id;
		brick br = brick_get_by_id(brick_id);
	
		br.x = (tile_x * BRICK_WIDTH) + pos_x;	
		br.y = (tile_y * BRICK_HEIGHT) + pos_y;
		
		brick_update(brick_id, br);

		return (tile_y * GRID_WIDTH) + tile_x;		
	}
	printf("CANNOT PUT IN ALREADY TAKEN SPACE\n");
	printf("GRID SAPCE: ");
	for(int i = 0; i < GRID_CAPACITY; ++i){
		printf("%i,", bricks[i]);
	}
	printf("\n");
	return -1;
}

























