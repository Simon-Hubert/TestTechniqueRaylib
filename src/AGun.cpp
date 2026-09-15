#include "Projectile.h"
#include "ProjectilePool.h"
#include "Texture.h"
#include "UpdateRegistry.h"
#include "raylib.h"
#include <AGun.h>
#include <iostream>
#include <memory>

namespace LilShip{

    AGun::AGun(){
        UpdateRegistry::Instance().RegisterUpdatable(this);
        projTexture = std::make_shared<Texture>("resources/newAssetPack/Blaster.png");
    }

    AGun::~AGun(){
        UpdateRegistry::Instance().UnRegisterUpdatable(this);
    }

    void AGun::Fire(const Vector2& position){
        if(canShoot){
            Shoot(position);
            canShoot = false;
            cooldown = 1.f/fireRate;
        }
    }

    void AGun::Update(float deltaTime){
        cooldown -= deltaTime;
        if(cooldown < 0.f){
            canShoot = true;
        }
    }

    void AGun::Shoot(const Vector2& position){
        std::cout << "Shoot" << std::endl;
        std::shared_ptr<Projectile> proj = ProjectilePool::Instance().GetProjectile({projTexture, 40.f, 1});
        proj->Init(position, {1,0});
    }
}
