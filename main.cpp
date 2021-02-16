#include "raylib.h"
#include "common.h"

#include "brick.h"
#include "grid.h"
#include "grab.h"
#include "holder.h"
#include "bag.h"

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



		if(IsKeyPressed(KEY_N)){
			int n_id = bag_get_next_id();
			if(holder_put_in_free_space(n_id) == -1)
				bag_put_back(n_id);
		}
    }
}

int main(void)
{
	create_window(1366, 768, "Rummy", 60);
	brick_generate_all();
	bag_reset();
	holder_init(1366 - (BRICK_WIDTH * HOLDER_WIDTH), 768 - (BRICK_HEIGHT * HOLDER_HEIGHT));
	grid_init(0, 0);
	holder_put_in_free_space(bag_get_next_id());	
	holder_put_in_free_space(bag_get_next_id());	
	holder_put_in_free_space(bag_get_next_id());	
	loop();
    CloseWindow();
    return 0;
}








