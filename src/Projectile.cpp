#include "DrawRegistry.h"
#include "ProjectilePool.h"
#include "UpdateRegistry.h"
#include "raylib.h"
#include <Projectile.h>
#include <iostream>
#include "Math.h"

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

    void Projectile::SetData(ProjectileData projectileData, std::shared_ptr<Projectile> ownPointer){
        sprite.ChangeTexture(projectileData.texture);
        speed = projectileData.speed;
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
        std::cout << "Projectile Drawn" << std::endl;

        if(!isActive) return;
        sprite.Draw(position, 0, 1);
    }

    void Projectile::Update(float deltaTime){
        std::cout << "Projectile Updated" << std::endl;

        if(!isActive) return;
        position += direction * speed * deltaTime;
    }

    void Projectile::Destroy(){
        isActive = false;
        ProjectilePool::Instance().ReturnProjectile(self);
    }
}
