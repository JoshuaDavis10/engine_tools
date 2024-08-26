#include "../include/raylib.h"

#include "defines.h"
#include "logger.h"

int main() {

	InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "event handler demo");
	SetTargetFPS(144);

	while(!WindowShouldClose()) {
		BeginDrawing();

			ClearBackground(BLACK);

		EndDrawing();
	}

	return 0;
}
