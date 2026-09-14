#include "Window.h"
#include "raylib.h"
#include "Game.h"

int main(int argc, char** argv) {
    SetConfigFlags(FLAG_VSYNC_HINT | FLAG_WINDOW_HIGHDPI);
    LilShip::Window window(800, 600, "Hello Showmielle");
    LilShip::Game game;

    while (!WindowShouldClose())
    {
        game.Update(GetFrameTime());

        BeginDrawing();
        ClearBackground(BLACK);
        game.Draw();
        EndDrawing();
    }
    
    return 0;
}
