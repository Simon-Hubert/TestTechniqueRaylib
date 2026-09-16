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
            
            void Draw(Vector2 position, float rotation, float scale) const;
            void ChangeTexture(std::shared_ptr<const Texture> texture);
            void ChangeTexture(std::shared_ptr<const Texture> texture, Vector2 size);

            Vector2 GetSize() const;
            
        private:
            Vector2 _size;
            std::shared_ptr<const Texture> _texture;
    };
}

