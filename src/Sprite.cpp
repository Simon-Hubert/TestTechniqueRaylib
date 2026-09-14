#include "raylib.h"
#include <Sprite.h>

namespace LilShip{

    Sprite::Sprite(std::shared_ptr<const Texture> texture, Vector2 size) :
    size(size),
    texture(std::move(texture))
    { }

    Sprite::Sprite(std::shared_ptr<const Texture> texture) :
    size(texture->GetSize()),
    texture(std::move(texture))
    { }

    void Sprite::Draw(Vector2 position, float rotation, Vector2 scale) const{
        texture->Draw(position, rotation, scale.x);
    }
}
