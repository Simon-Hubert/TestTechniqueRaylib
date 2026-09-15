#include "Ship.h"
#include <memory>

#include "InputManager.h"
#include <iostream>

namespace LilShip {
    Ship::Ship(std::shared_ptr<const Texture> texture):
    sprite(std::make_unique<Sprite>(texture)),
    position({200.f, 200.f}),
    scale(2)
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
    }

    void Ship::Update(float deltaTime)
    {
        position.x += inputs.x;
        position.y += inputs.y;
    }

    void Ship::Draw()
    {
        sprite->Draw(position, rotation, scale);
    }
}
