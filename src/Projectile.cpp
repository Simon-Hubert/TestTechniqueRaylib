#include "DrawRegistry.h"
#include "ProjectilePool.h"
#include "UpdateRegistry.h"
#include "raylib.h"
#include <Projectile.h>
#include <iostream>
#include "FMath.h"

namespace LilShip{
    Projectile::Projectile():
    sprite(nullptr, {0,0})
    {
        DrawRegistry::Instance().RegisterDrawable(this);
        UpdateRegistry::Instance().RegisterUpdatable(this);
        std::cout << "Projectile Constructed" << std::endl;
    }


    Projectile::~Projectile(){
        DrawRegistry::Instance().UnRegisterDrawable(this);
        UpdateRegistry::Instance().UnRegisterUpdatable(this);
    }

    void Projectile::SetData(const ProjectileData& projectileData, const std::shared_ptr<Projectile>& ownPointer){
        sprite.ChangeTexture(projectileData.texture);
        speed = projectileData.speed;
        self = ownPointer;
        damages = projectileData.damages;
        std::cout << "Projectile SetData" << std::endl;   
    }

    void Projectile::Init(Vector2 newPosition, Vector2 newDirection){
        position = newPosition;
        direction = newDirection;
        isActive = true;
        std::cout << "Projectile Init" << std::endl;
    }

    void Projectile::Reset(){
        sprite.ChangeTexture(nullptr, {0,0});
    }

    void Projectile::Draw() const{
        if(!isActive) return;
        sprite.Draw(position, 0, 1);
    }

    void Projectile::Update(float deltaTime){
        if(!isActive) return;
        position += direction * speed * deltaTime;
        if(position.x >= 850.f) Destroy();
    }

    void Projectile::Destroy(){
        isActive = false;
        ProjectilePool::Instance().ReturnProjectile(self);
    }
}
