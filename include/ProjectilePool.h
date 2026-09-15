#pragma once

#include "Projectile.h"
#include <memory>
#include <vector>

namespace LilShip{

    class ProjectilePool
    {
        public:
            ProjectilePool();
            ProjectilePool(const ProjectilePool&) = delete;
            ProjectilePool(ProjectilePool&&) = delete;
            ~ProjectilePool();

            ProjectilePool& operator=(const ProjectilePool&) = delete;
            ProjectilePool& operator=(ProjectilePool&&) = delete;

            static ProjectilePool& Instance();

            std::shared_ptr<Projectile> GetProjectile(ProjectileData projectileData);
            void ReturnProjectile(std::shared_ptr<Projectile> projectile);

        private:
            static ProjectilePool* instance;
            std::vector<std::shared_ptr<Projectile>> projectilePool;
    };
}

