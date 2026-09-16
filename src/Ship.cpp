#include "Ship.h"

#include <iostream>
#include <memory>

#include "AGun.h"
#include "EnemyPool.h"
#include "InputManager.h"
#include "FMath.h"
#include "UpdateRegistry.h"
#include "raylib.h"

namespace LilShip {
    class Enemy;

    Ship::Ship(Vector2 position, float maxSpeed, std::shared_ptr<const Texture> texture):
    sprite(std::make_unique<Sprite>(texture)),
    _position(position),
    _maxSpeed(maxSpeed),
    gun(std::make_unique<AGun>())
    {
        InputManager::Instance().BindKey(KEY_UP, "Up");
        InputManager::Instance().BindAction("Up", [&](KeyState state)
        {
            if(state == PRESSED) _inputs.y -= 1;
            if(state == RELEASED) _inputs.y += 1;
        });
        InputManager::Instance().BindKey(KEY_DOWN, "Down");
        InputManager::Instance().BindAction("Down", [&](KeyState state)
        {
            if(state == PRESSED) _inputs.y += 1;
            if(state == RELEASED) _inputs.y -= 1;
        });
        InputManager::Instance().BindKey(KEY_LEFT, "Left");
        InputManager::Instance().BindAction("Left", [&](KeyState state)
        {
            if(state == PRESSED) _inputs.x -= 1;
            if(state == RELEASED) _inputs.x += 1;
        });
        InputManager::Instance().BindKey(KEY_RIGHT, "Right");
        InputManager::Instance().BindAction("Right", [&](KeyState state)
        {
            if(state == PRESSED) _inputs.x += 1;
            if(state == RELEASED) _inputs.x -= 1;
        });

        InputManager::Instance().BindKey(KEY_SPACE, "Shoot");
        InputManager::Instance().BindAction("Shoot", [this](KeyState state)
        {
            if (state == PERFORMED) {
                gun->Fire(_position);
            }
        });

        DrawRegistry::Instance().RegisterDrawable(this);
        UpdateRegistry::Instance().RegisterUpdatable(this);
        
        _size = sprite->GetSize();
    }

    Ship::Ship(std::shared_ptr<const Texture> texture):
    Ship({0,0}, 5, texture)
    {   }

    Ship::~Ship(){
        DrawRegistry::Instance().UnRegisterDrawable(this);
        UpdateRegistry::Instance().UnRegisterUpdatable(this);
    }

    void Ship::Update(float deltaTime)
    {
        _speed += _inputs * _maxSpeed;
        _speed -= _speed * 0.1f;
        
        _position += _speed * deltaTime;
        
        //collisions
        for(std::shared_ptr<Enemy> enemy: *EnemyPool::Instance().GetActiveEnemies()) {
            if(!enemy)continue;
            if(CheckCollisionCircleRec(_position, 10, enemy->GetCollisionRect())) {
                
                //Logique on death
            }
        }
    }

    void Ship::Draw() const
    {
        sprite->Draw(_position, _rotation, _scale);
    }
}
