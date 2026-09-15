#pragma once

#include "Ship.h"
#include <memory>

namespace LilShip {

    class Game {
        public:
            Game();
            Game(const Game&) = delete;
            Game(Game&&) noexcept = default;
            ~Game();
            Game& operator=(const Game&) = delete;
            Game& operator=(Game&&) = default;

        private:
            std::unique_ptr<Ship> ship;

    };
}
