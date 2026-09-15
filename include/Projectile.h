#pragma once

#include "DrawRegistry.h"
#include "Sprite.h"
#include "Texture.h"
#include "UpdateRegistry.h"
#include "raylib.h"
#include <memory>

namespace LilShip{

    struct ProjectileData{
        std::shared_ptr<const Texture> texture;
        float speed;
        int damages;
    };

    class Projectile : public IUpdatable, public IDrawable
    {
        public:
            Projectile();
            Projectile(const Projectile&) = delete;
            Projectile(Projectile&&) = delete;
            ~Projectile();

            Projectile& operator=(const Projectile&) = delete;
            Projectile& operator=(Projectile&&) = delete;

            void Draw() const override;
            void Update(float deltaTime) override;

            void SetData(const ProjectileData& projectileData, const std::shared_ptr<Projectile>& ownPointer);
            void Init(Vector2 newPosition, Vector2 newDirection);
            void Reset();

        private:
            Vector2 position;
            Vector2 direction;
            float rotation = 0;
            float speed;
            int damages;
            bool isActive = false;
            Sprite sprite;
            std::shared_ptr<Projectile> self;

            void Destroy();
    };
}

