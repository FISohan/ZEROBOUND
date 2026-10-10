

#include "raylib.h"
#include "core/game.h"
#include "core/player.h"
#include "resource_dir.h" // utility header for SearchAndSetResourceDir

int main()
{
	Game game;
	init_game(&game);
	SetConfigFlags(FLAG_VSYNC_HINT | FLAG_WINDOW_HIGHDPI);
	SetConfigFlags(FLAG_MSAA_4X_HINT);

	// SetConfigFlags(FLAG_FULLSCREEN_MODE);
	InitWindow(800, 600, "Hello Fahim");
	// game loop
	while (!WindowShouldClose())
	{
		/// Updating
		update_game(&game);
		//////////////
		// Drawing
		BeginDrawing();
		ClearBackground(BLACK);
		render_game(&game);
		EndDrawing();
		///////////////
	}
	CloseWindow();
	return 0;
}
