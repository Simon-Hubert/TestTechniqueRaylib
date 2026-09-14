#pragma once

#include "Sprite.h"
#include "raylib.h"
#include <memory>

namespace LilShip {

    class Game;

    class Ship{
        
        friend Game;

        public: 
            Ship(std::shared_ptr<const Texture> texture);
            Ship(const Ship&) = delete;
            Ship(Ship&&) noexcept = default;
            ~Ship() = default;
            Ship& operator=(const Ship&) = delete;
            Ship& operator=(Ship&&) = default;
        
        private:
            Vector2 position;
            float rotation;
            Vector2 scale;

            Vector2 speed;

            std::unique_ptr<Sprite> sprite;

            void Update(float deltaTime);
            void Draw();
    };
}
