#include "raylib.h"
#include <vector>

// Function to calculate Fibonacci sequence
std::vector<int> fibonacciSequence(int n) {
    std::vector<int> sequence;
    sequence.push_back(0);
    sequence.push_back(1);

    for (int i = 2; i <= n; ++i) {
        sequence.push_back(sequence[i - 1] + sequence[i - 2]);
    }

    return sequence;
}

int main() {
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "Fibonacci Cubes");
    SetTargetFPS(60);

    Camera3D camera = { 0 };
    camera.position = { 10.0f, 10.0f, 10.0f };
    camera.target = { 0.0f, 0.0f, 0.0f };
    camera.up = { 0.0f, 1.0f, 0.0f };
    camera.fovy = 45.0f;
    camera.projection = CAMERA_PERSPECTIVE;

    std::vector<int> fibSequence = fibonacciSequence(20);

    Vector2 oldMousePosition = GetMousePosition();

    while (!WindowShouldClose()) {
        // Camera movement based on user input
        Vector2 newMousePosition = GetMousePosition();
        float deltaX = newMousePosition.x - oldMousePosition.x;
        float deltaY = newMousePosition.y - oldMousePosition.y;

        camera.target.x += deltaX * 0.1f;
        camera.target.y -= deltaY * 0.1f;

        oldMousePosition = newMousePosition;

        // Update
        UpdateCamera(&camera, 0.01f); // Adjust the movement speed as needed

        BeginDrawing();
        ClearBackground(RAYWHITE);

        BeginMode3D(camera);

        for (std::size_t i = 0; i < fibSequence.size(); ++i) {
            // Color animation
            Vector3 hsv = { (float)GetTime()*30.0f, 0.8f, 0.8f };
            Color color = ColorFromHSV(hsv.x, hsv.y, hsv.z);

            // Cube position and size based on Fibonacci value
            Vector3 cubePosition = { (float)fibSequence[i], 0.0f, 0.0f };
            Vector3 cubeSize = { 1.0f, (float)fibSequence[i], 1.0f };

            DrawCube(cubePosition, cubeSize.x, cubeSize.y, cubeSize.z, color);
        }

        EndMode3D();

        EndDrawing();
    }

    CloseWindow();

    return 0;
}
