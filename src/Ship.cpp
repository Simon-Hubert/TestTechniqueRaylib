#include "Ship.h"
#include <memory>

namespace LilShip {
    Ship::Ship(std::shared_ptr<const Texture> texture):
    sprite(std::make_unique<Sprite>(texture)),
    position({200.f, 200.f}),
    scale({1,1}),
    rotation(0)
    {

    }

    void Ship::Update(float deltaTime)
    {
        
    }

    void Ship::Draw()
    {
        sprite->Draw(position, rotation, scale);
    }
}