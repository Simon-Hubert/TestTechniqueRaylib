#include <Enemy.h>
#include <iostream>

#include "EnemyPool.h"
#include "Sprite.h"
#include "FMath.h"
#include "Score.h"

namespace LilShip{

    Enemy::Enemy(std::shared_ptr<const Texture> texture, int id) :
    id(id),
    _sprite(texture)
    {
        DrawRegistry::Instance().RegisterDrawable(this);
        UpdateRegistry::Instance().RegisterUpdatable(this);
        size = _sprite.GetSize();
        position = {850, 300};
        
    }

    Enemy::~Enemy()
    {
        DrawRegistry::Instance().UnRegisterDrawable(this);
        UpdateRegistry::Instance().UnRegisterUpdatable(this);
    }
    
    void Enemy::Draw() const
    {
        if(!active) return;
        _sprite.Draw(position + size, 180, 1);
    }

    void Enemy::Update(float deltaTime)
    {
        if(!active) return;
        if(position.x < -50) Death();
        position -= Vector2{400* deltaTime,0};
        
    }

    Rectangle Enemy::GetCollisionRect() const
    {
        return {position.x, position.y, size.x, size.y};
    }

    void Enemy::Spawn(Vector2 newPosition)
    {
        position = newPosition;
        health = 3;
        active = true;
    }

    void Enemy::TakeDamage(int damages)
    {
        health -= damages;
        if(health <= 0) {
            Score::Instance().Add(100);
            Death();
        }
    }

    void Enemy::Death()
    {
        active = false;
        EnemyPool::Instance().ReturnEnemy(id);
    }
}
