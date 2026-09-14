#include "raylib.h"
#include <Texture.h>

namespace LilShip{
    Texture::Texture(std::string path)
    {
        texture  = LoadTexture(path.c_str());
        _source = {
            .x =  0,
            .y =  0,
            .width =  (float)texture.width,
            .height =  (float)texture.height
        };
    }

    Texture::~Texture()
    {
        UnloadTexture(texture);
    }


    void Texture::DrawRec(Rectangle source, Rectangle dest, Vector2 pos) const
    {
        DrawTexturePro(texture, source, dest, pos, 0, WHITE);
    }

    void Texture::DrawTo(Rectangle dest, Vector2 pos, float rotation) const
    {
        DrawTexturePro(texture, _source, dest, pos, rotation, WHITE);
    }

    void Texture::Draw(Vector2 position, float rotation, float scale) const 
    {
        DrawTextureEx(texture, position, rotation, scale, WHITE);
    }

    Vector2 Texture::GetSize() const{
        return {(float)texture.width, (float)texture.height};
    }
}


