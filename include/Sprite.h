#pragma once

#include "Texture.h"
#include "raylib.h"
#include <memory>

namespace LilShip{

    class Sprite
    {
        public:
        Sprite(std::shared_ptr<const Texture> texture, Vector2 size);
        Sprite(std::shared_ptr<const Texture> texture);
        Sprite(const Sprite&) = delete;
            Sprite(Sprite&&) = delete;
            ~Sprite() = default;

            Sprite& operator=(const Sprite&) = delete;
            Sprite& operator=(Sprite&&) = delete;
            
            void Draw(Vector2 position, float rotation, Vector2 scale) const;

        private:
            Vector2 size;
            std::shared_ptr<const Texture> texture;
    };
}

