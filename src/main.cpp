#include "raylib.h"

int main()
{
    Color darkGreen = Color{20, 160, 133, 255};
    Color red = Color{255, 0, 0, 255};
    Color rayWhite = Color{245, 245, 245, 255};

    const int screenWidth = 800;
    const int screenHeight = 450;

    int direction = 10;

    InitWindow(screenWidth, screenHeight, "My first RAYLIB program!");
    SetTargetFPS(60);

    // Circle variables
    int circleX = screenWidth / 4;
    int circleY = screenHeight / 4;
    int radius = 50;
    
    // Circle edges
    int circleRight = circleX + radius;
    int circleLeft = circleX - radius;
    int circleUp = circleY - radius;
    int circleDown = circleY + radius;

    // Rectangle variables
    int rectX {400};
    int rectY{0};
    int rectWidth{50}, rectHeight{50};

    // Rectangle edges





    // While this function returns false, the window should stay open
    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(rayWhite);

        // Add code to make sure the circle doesn't go off screen


        // Draw the circle and rectangle
        DrawCircle(circleX, circleY, radius, darkGreen);
        DrawRectangle(rectX, rectY, rectWidth, rectHeight, red);
        
        // Making the rectangle go up and down
        rectY += direction;

        if(rectY > 450 || rectY < 0) {
            direction = -direction;
        }


        if (IsKeyDown(KEY_RIGHT) && circleX < 750) {
            circleX+=2;
        }

        if (IsKeyDown(KEY_LEFT) && circleX > 50) {
            circleX-=2;
        }

        if (IsKeyDown(KEY_DOWN) && circleY < 550) {
            circleY+=2;
        }

        if (IsKeyDown(KEY_UP) && circleY > 50) {
            circleY-=2;
        }




        EndDrawing();
    }

    CloseWindow();
    return 0;
}