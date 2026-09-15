#include "Ship.h"
#include <memory>

#include "InputManager.h"
#include "Math.h"
#include "UpdateRegistry.h"

namespace LilShip {
    
    Ship::Ship(Vector2 position, float maxSpeed, std::shared_ptr<const Texture> texture):
    sprite(std::make_unique<Sprite>(texture)),
    position(position),
    maxSpeed(maxSpeed)
    {
        InputManager::Instance().BindKey(KEY_UP, "Up");
        InputManager::Instance().BindAction("Up", [&](KeyState state)
        {
            if(state == PRESSED) inputs.y -= 1;
            if(state == RELEASED) inputs.y += 1;
        });
        InputManager::Instance().BindKey(KEY_DOWN, "Down");
        InputManager::Instance().BindAction("Down", [&](KeyState state)
        {
            if(state == PRESSED) inputs.y += 1;
            if(state == RELEASED) inputs.y -= 1;
        });
        InputManager::Instance().BindKey(KEY_LEFT, "Left");
        InputManager::Instance().BindAction("Left", [&](KeyState state)
        {
            if(state == PRESSED) inputs.x -= 1;
            if(state == RELEASED) inputs.x += 1;
        });
        InputManager::Instance().BindKey(KEY_RIGHT, "Right");
        InputManager::Instance().BindAction("Right", [&](KeyState state)
        {
            if(state == PRESSED) inputs.x += 1;
            if(state == RELEASED) inputs.x -= 1;
        });

        DrawRegistry::Instance().RegisterDrawable(this);
        UpdateRegistry::Instance().RegisterUpdatable(this);
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
        speed += inputs * maxSpeed;
        speed -= speed * 0.1f;
        
        position += speed * deltaTime;
    }

    void Ship::Draw() const
    {
        sprite->Draw(position, rotation, scale);
    }
}
