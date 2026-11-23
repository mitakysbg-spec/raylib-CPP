#include "raylib.h"

int main(void)
{
    int playerX = 0;
    int playerY = 0;
    int size = 50;
    int speed = 1;

    SetConfigFlags(FLAG_WINDOW_RESIZABLE | FLAG_VSYNC_HINT);

    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "GameTest");

    SetTargetFPS(100);         // Set our game to run at 60 frames-per-second

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {


        if (IsKeyPressed(KEY_F11)) ToggleBorderlessWindowed();
        
        if (IsKeyPressed(KEY_H))
        {
            playerX = 10;
            playerY = 200;
        }

        if (IsKeyPressed(KEY_R)) {
            playerX = 10;
            playerY = 200;
            size = 50;
            speed = 1;
        }

        BeginDrawing();

        ClearBackground(BLACK);
        DrawFPS(10, 10);
        DrawText(TextFormat("X position: %d", playerX), 10, 40, 20, RED);
        DrawText(TextFormat("Y position: %d", playerY), 10, 60, 20, RED);
        DrawText(TextFormat("Speed: %d", speed), 10, 80, 20, RED);
        DrawText("Press H teleport", 10, 400, 50, RED);
        DrawText("Press R to Reset", 10, 350, 50, RED);
        DrawRectangle(playerX, playerY, size, size, WHITE);
        EndDrawing();

        if (IsKeyDown(KEY_A)) playerX = playerX - speed;
        if (IsKeyDown(KEY_D)) playerX = playerX + speed;
        if (IsKeyDown(KEY_W)) playerY = playerY - speed;
        if (IsKeyDown(KEY_S)) playerY = playerY + speed;
        
        if(size > 1) if (IsKeyDown(KEY_LEFT)) size -=1;
        if (IsKeyDown(KEY_RIGHT)) size += 1;
        
        if (IsKeyPressed(KEY_UP)) speed += 1;
        if (speed > 1) if (IsKeyPressed(KEY_DOWN)) speed -= 1;
            
        
    }

    
    CloseWindow();        // Close window and OpenGL context
    
    return 0;
}
