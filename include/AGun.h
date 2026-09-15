#pragma once

#include "Projectile.h"
#include "Texture.h"
#include "UpdateRegistry.h"
#include <memory>

namespace LilShip{

    class AGun : public IUpdatable
    {
        public:
            AGun();
            AGun(const AGun&) = delete;
            AGun(AGun&&) = delete;
            ~AGun();

            AGun& operator=(const AGun&) = delete;
            AGun& operator=(AGun&&) = delete;

            void Fire(Vector2 position);

            void Update(float deltaTime);

        private:
            bool canShoot = true;
            virtual void Shoot(Vector2 position);

        protected:
            float cooldown = 0.f;
            float fireRate = 5.f;
            ProjectileData projectileData;
            std::shared_ptr<Texture> projTexture;
    };
}

