#pragma once

#include "AGun.h"
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
            Vector2 _position;
            float _rotation = 0.f;
            float _scale = 1.f;
            float _maxSpeed;
            
            Vector2 _inputs = {0,0};

            Vector2 _speed = {0,0};

            std::unique_ptr<Sprite> sprite;

            void Draw() const override;
            void Update(float deltaTime) override;

            std::unique_ptr<AGun> gun;            
    };
}
