#include "Projectile.h"
#include <ProjectilePool.h>
#include <memory>
#include <stdexcept>

namespace LilShip{

    ProjectilePool::ProjectilePool() {
        if(instance != nullptr) {
            throw std::runtime_error("Il y a deja une instance d'input manager");
        }
        instance = this;
    }

    ProjectilePool::~ProjectilePool() {
        instance = nullptr;
    }

    ProjectilePool& ProjectilePool::Instance() {
        if(!instance) {
            throw std::runtime_error("ProjectilePool hasn't been instanced");
        }
        return *instance;
    }

    ProjectilePool* ProjectilePool::instance = nullptr;

    std::shared_ptr<Projectile> ProjectilePool::GetProjectile(ProjectileData projectileData){
        if(!projectilePool.empty()){
            std::shared_ptr<Projectile> proj = projectilePool.back();
            projectilePool.pop_back();
            proj->SetData(projectileData, proj);
            return proj;
        }
        else{
            std::shared_ptr<Projectile> proj = std::make_shared<Projectile>();
            proj->SetData(projectileData, proj);
            return proj;
        }
    }

    void ProjectilePool::ReturnProjectile(std::shared_ptr<Projectile> projectile){
        projectile->Reset();
        projectilePool.push_back(std::move(projectile));
    }
}
