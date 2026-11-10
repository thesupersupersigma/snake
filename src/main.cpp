#include <iostream>
#include <raylib.h>
#include <vector>

int main() {

    const int screenHeight = 720;
    const int screenWidth = 1280;

    int directionX = 1;
    int directionY = 0;
    float timer = 0.0f;

    struct snakePos {
        int x;
        int y;
    };

    std::vector<snakePos> snake = {
        {100, 100},
        {70, 100},
        {40, 100}
    };

    InitWindow(screenWidth, screenHeight, "Snake");
    SetTargetFPS(60);

    while (!WindowShouldClose()) {

        // Keyboard input
        if (IsKeyPressed(KEY_W) && directionY != 1) {
            directionX = 0;
            directionY = -1;
        }
        else if (IsKeyPressed(KEY_S) && directionY != -1) {
            directionX = 0;
            directionY = 1;
        }
        else if (IsKeyPressed(KEY_A) && directionX != 1) {
            directionX = -1;
            directionY = 0;
        }
        else if (IsKeyPressed(KEY_D) && directionX != -1) {
            directionX = 1;
            directionY = 0;
        }

        // Movement timer
        timer += GetFrameTime();

        if (timer >= 0.15f) {

            snakePos newHead = {
                snake[0].x + directionX * 30,
                snake[0].y + directionY * 30
            };

            snake.insert(snake.begin(), newHead);
            snake.pop_back();

            timer -= 0.15f;
        }

        // Drawing
        BeginDrawing();
        ClearBackground(BLACK);

        for (const snakePos& segment : snake) {
            DrawRectangle(segment.x, segment.y, 30, 30, GREEN);
        }

        EndDrawing();
    }

    CloseWindow();
    return 0;
}