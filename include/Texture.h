#pragma once

#include <raylib.h>
#include <string>


namespace LilShip{

    class Texture
    {
        public:
            Texture(std::string path);
            Texture(const Texture&) = delete;
            Texture(Texture&&) = delete;
            ~Texture();

            Texture& operator=(const Texture&) = delete;
            Texture& operator=(Texture&&) = delete;

            void DrawRec(Rectangle source, Rectangle dest, Vector2 pos) const;
            void DrawTo(Rectangle rect, Vector2 pos, float rotation) const;
            void Draw(Vector2 position, float rotation, float scale) const;

            Vector2 GetSize() const;
        private:
            Texture2D texture;
            Rectangle _source;
    };
}

