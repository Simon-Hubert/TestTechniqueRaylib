#include "UpdateRegistry.h"
#include "Window.h"
#include "raylib.h"
#include "Game.h"
#include "InputManager.h"
#include "DrawRegistry.h"

int main(int argc, char** argv) {
    SetConfigFlags(FLAG_VSYNC_HINT | FLAG_WINDOW_HIGHDPI);
    LilShip::Window window(800, 600, "Hello Showmielle");
    LilShip::InputManager inputManager;
    LilShip::DrawRegistry drawRegistry;
    LilShip::UpdateRegistry updateRegistry;
    LilShip::Game game;

    while (!WindowShouldClose())
    {
        inputManager.Update();
        updateRegistry.Update(GetFrameTime());

        BeginDrawing();
        ClearBackground(BLACK);
        drawRegistry.Draw();
        EndDrawing();
    }
    
    return 0;
}
