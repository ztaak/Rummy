#include "raylib.h"
#include "common.h"

#include "brick.h"
#include "grid.h"
#include "grab.h"
#include "holder.h"
#include "bag.h"
#include "state.h"


void create_window(int width, int height, std::string title, int fps){
    InitWindow(width, height, title.c_str());
    SetTargetFPS(fps);
}


void loop(){
    while (!WindowShouldClose())    {
        BeginDrawing();

        ClearBackground(RAYWHITE);
		
		
		brick_draw_all();

		grab_update();

		holder_draw();
		grid_draw();	

		DrawText(TextFormat("%i", brick_get_id_by_pos(GetMousePosition().x, GetMousePosition().y)), 10, 10, 15, BLACK);	
		bag_draw_content(10, 30); 
    	EndDrawing();

		if(IsKeyPressed(KEY_S)){
			state_save();
		}
		
		if(IsKeyPressed(KEY_R)){
			state_restore();
		}

		if(IsKeyPressed(KEY_C)){
			if(!grid_check_pairs())
				state_restore();
			else
				state_save();
		}

		if(IsKeyPressed(KEY_N)){
			int n_id = bag_get_next_id();
			if(holder_put_in_free_space(n_id) == -1)
				bag_put_back(n_id);
			state_save();
		}
    }
}

int main(void)
{
	create_window(SCREEN_WIDTH, SCREEN_HEIGHT, "Rummy", 60);
	brick_generate_all();
	bag_reset();
	holder_init((SCREEN_WIDTH - (BRICK_WIDTH * HOLDER_WIDTH)) / 2, SCREEN_HEIGHT - (BRICK_HEIGHT * HOLDER_HEIGHT));
	grid_init((SCREEN_WIDTH - (BRICK_WIDTH * GRID_WIDTH)) / 2, 0);
	for(int i = 0; i < NUM_OF_BRICKS_AT_START; ++i){
		holder_put_in_free_space(bag_get_next_id());
	}
	loop();
    CloseWindow();
    return 0;
}








