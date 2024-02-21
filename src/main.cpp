#include "raylib.h"

int main()
{
    Color darkGreen = Color{20, 160, 133, 255};
    Color red = Color{255, 0, 0, 255};
    Color rayWhite = Color{245, 245, 245, 255};

    const int screenWidth{800};
    const int screenHeight{450};

    int direction{10};
    int circleSpeed{5};

    bool collisionWithRect{false};

    InitWindow(screenWidth, screenHeight, "My first RAYLIB program!");
    SetTargetFPS(60);

    // Circle variables
    int circleX{screenWidth / 4};
    int circleY{screenHeight / 4};
    int circleRadius{25};
    
    // Circle edges
    int circleRightEdge{circleX + circleRadius};
    int circleLeftEdge{circleX - circleRadius};
    int circleTopEdge{circleY - circleRadius};
    int circleBottomEdge{circleY + circleRadius};


    // Rectangle variables
    int rectX {400};
    int rectY{0};
    int rectWidth{50}, rectHeight{50};

    // Rectangle edges
    int rectRightEdge{rectX + rectWidth};
    int rectLeftEdge{rectX};
    int rectTopEdge{rectY};
    int rectBottomEdge{rectY + rectHeight};


    // While this function returns false, the window should stay open
    while (!WindowShouldClose())
    {

        BeginDrawing();
        ClearBackground(rayWhite);

        if (collisionWithRect) {
            DrawText("GAME OVER", 400, 200, 20, red);
        } else {     
            // Draw the circle and rectangle
            DrawCircle(circleX, circleY, circleRadius, darkGreen);
            DrawRectangle(rectX, rectY, rectWidth, rectHeight, red);
            
            // Draw the text
            DrawText("Move the circle with the arrow keys", 10, 10, 20, darkGreen);

            // Making the rectangle go up and down
            rectY += direction;

            if(rectY > screenHeight || rectY < 0) {
                direction = -direction;
            }


            if (IsKeyDown(KEY_RIGHT) && circleX < screenWidth - 5) {
                circleX+=circleSpeed;
            }

            if (IsKeyDown(KEY_LEFT) && circleX > 5) {
                circleX-=circleSpeed;
            }

            if (IsKeyDown(KEY_DOWN) && circleY < screenHeight - 5) {
                circleY+=circleSpeed;
            }

            if (IsKeyDown(KEY_UP) && circleY > 5) {
                circleY-= circleSpeed;
            }
        }

        EndDrawing();
    }

    CloseWindow();
    return 0;
}