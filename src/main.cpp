#include "raylib.h"

int main()
{
    Color darkGreen = Color{20, 160, 133, 255};

    const int screenWidth = 800;
    const int screenHeight = 600;

    InitWindow(screenWidth, screenHeight, "My first RAYLIB program!");
    SetTargetFPS(60);

    int circleX = screenWidth / 2;
    int circleY = screenHeight / 2;
    int radius = 50;
    Color red = Color{255, 0, 0, 255};
    
    // While this function returns false, the window should stay open
    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(darkGreen);
        // Add code to make sure the circle doesn't go off screen

        if (circleX < 750) {
            if (IsKeyDown(KEY_RIGHT)) circleX+=2;
        }

        if (circleX > 50) {
            if (IsKeyDown(KEY_LEFT)) circleX-=2;
        }

        if (circleY < 550) {
            if (IsKeyDown(KEY_DOWN)) circleY+=2;
        }

        if (circleY > 50) {
            if (IsKeyDown(KEY_UP)) circleY-=2;
        }


        
        if(IsKeyDown(KEY_EQUAL)) radius++;

        if(IsKeyDown(KEY_MINUS)) radius--;

        DrawCircle(circleX, circleY, radius, red);

        EndDrawing();
    }

    CloseWindow();
    return 0;
}