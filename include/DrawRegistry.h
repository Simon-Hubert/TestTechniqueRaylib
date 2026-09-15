#pragma once

#include <vector>

namespace LilShip{

    class IDrawable{
        public:
            virtual void Draw() const = 0;
    };

    class DrawRegistry
    {
        public:
            DrawRegistry();
            DrawRegistry(const DrawRegistry&) = delete;
            DrawRegistry(DrawRegistry&&) = delete;
            ~DrawRegistry();

            DrawRegistry& operator=(const DrawRegistry&) = delete;
            DrawRegistry& operator=(DrawRegistry&&) = delete;

            static DrawRegistry& Instance();

            void Draw() const;
            void RegisterDrawable(IDrawable* drawable);
            void UnRegisterDrawable(IDrawable* drawable);

        private:
            std::vector<IDrawable*> drawables;
            static DrawRegistry* instance;
    };
}

