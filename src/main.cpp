#include "Window.h"
#include "raylib.h"
#include "Game.h"
#include "InputManager.h"

int main(int argc, char** argv) {
    SetConfigFlags(FLAG_VSYNC_HINT | FLAG_WINDOW_HIGHDPI);
    LilShip::Window window(800, 600, "Hello Showmielle");
    LilShip::InputManager inputManager;
    LilShip::Game game;

    while (!WindowShouldClose())
    {
        inputManager.Update();
        game.Update(GetFrameTime());

        BeginDrawing();
        ClearBackground(BLACK);
        game.Draw();
        EndDrawing();
    }
    
    return 0;
}
