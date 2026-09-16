#pragma once

#include <memory>

#include "DrawRegistry.h"
#include "Sprite.h"
#include "Texture.h"
#include "UpdateRegistry.h"

namespace LilShip{
    class EnemyPool;
    class Sprite;

    class Enemy : public IUpdatable, public IDrawable
    {
        public:
            explicit Enemy(std::shared_ptr<const Texture> texture, int id);
            Enemy(const Enemy&) = delete;
            Enemy(Enemy&&) = delete;
            ~Enemy();

            Enemy& operator=(const Enemy&) = delete;
            Enemy& operator=(Enemy&&) = delete;

            void Draw() const override;
            void Update(float deltaTime) override;
        
            Rectangle GetCollisionRect() const;
    
            const int id;
        
            void Spawn(Vector2 newPosition);
        
        
        private:
            Vector2 position;
            Vector2 size;
            void Death();
            bool active = false;
            Sprite _sprite;
    };
}

