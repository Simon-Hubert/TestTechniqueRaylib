#include "raylib.h"
#include <Sprite.h>
#include <utility>

namespace LilShip{

    Sprite::Sprite(std::shared_ptr<const Texture> texture, Vector2 size) :
    _size(size),
    _texture(std::move(texture))
    { }

    Sprite::Sprite(std::shared_ptr<const Texture> texture) :
    _size(texture->GetSize()),
    _texture(std::move(texture))
    { }

    void Sprite::Draw(Vector2 position, float rotation, float scale) const{
        if(_texture) _texture->Draw(position, rotation, scale);
    }

    void Sprite::ChangeTexture(std::shared_ptr<const Texture> texture){
        _texture = std::move(texture);
        _size = _texture->GetSize();
    }

    void Sprite::ChangeTexture(std::shared_ptr<const Texture> texture, Vector2 size){
        _texture = std::move(texture);
        _size = size;
    }
}
