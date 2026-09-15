#pragma once

#include "DrawRegistry.h"
#include "Sprite.h"
#include "UpdateRegistry.h"
#include "raylib.h"
#include <memory>

namespace LilShip {

    class Game;

    class Ship : public IDrawable, public IUpdatable{
        
        friend Game;
        friend DrawRegistry;
        friend UpdateRegistry;

        public: 
            Ship(Vector2 position, float maxSpeed, std::shared_ptr<const Texture> texture);
            Ship(std::shared_ptr<const Texture> texture);
            Ship(const Ship&) = delete;
            Ship(Ship&&) noexcept = default;
            ~Ship();
            Ship& operator=(const Ship&) = delete;
            Ship& operator=(Ship&&) = default;
        
        private:
            Vector2 position;
            float rotation = 0.f;
            float scale = 1.f;
            float maxSpeed;
            
            Vector2 inputs = {0,0};

            Vector2 speed = {0,0};

            std::unique_ptr<Sprite> sprite;

            void Draw() const override;
            void Update(float deltaTime) override;
            
    };
}
