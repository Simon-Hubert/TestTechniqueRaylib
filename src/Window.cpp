#include "raylib.h"
#include <Window.h>

namespace LilShip{
    Window::Window(int width, int height, std::string title)
    {
        InitWindow(width, height, "Hello Raylib");
    }

    Window::~Window()
    {
        CloseWindow();
    }
}


