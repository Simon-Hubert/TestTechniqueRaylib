#pragma once

#include <string>

namespace LilShip{

    class Window
    {
        public:
            Window(int width, int height, std::string title);
            Window(const Window&) = delete;
            Window(Window&&) = delete;
            ~Window();

            Window& operator=(const Window&) = delete;
            Window& operator=(Window&&) = delete;
    };
}

