#include <iostream>
#include <raylib.h>

int main() {

	int y = 100;
	int x = 100;
	const int screenHeight = 720;
	const int screenWidth = 1280;
	int directionX = 1;
	int directionY = 0;
	float timer = 0.0f;

	InitWindow(screenWidth, screenHeight, "Snake");
	SetTargetFPS(60);

	Image favicon = LoadImage("favicon.ico");
	SetWindowIcon(favicon);
	UnloadImage(favicon);

	while (!WindowShouldClose()) {
		if (IsKeyPressed(KEY_W) && directionY != 1) {
			directionX = 0;
			directionY = -1;
		} else if (IsKeyPressed(KEY_S) && directionY != -1) {
			directionX = 0;
			directionY = 1;
		} else if (IsKeyPressed(KEY_A) && directionX != 1) {
			directionX = -1;
			directionY = 0;
		} else if (IsKeyPressed(KEY_D) && directionX != -1) {
			directionX = 1;
			directionY = 0;
		}
		
		timer += GetFrameTime();
		
		if (timer >= 0.15f) {
			x += directionX * 30;
			y += directionY * 30;
		
			timer -= 0.15f;
		}

		BeginDrawing();
		ClearBackground(BLACK);
		DrawRectangle(x, y, 30, 30, GREEN);
		EndDrawing();
	}

	CloseWindow();
	return 0;

}