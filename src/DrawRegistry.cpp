#include <DrawRegistry.h>
#include <algorithm>
#include <stdexcept>

namespace LilShip{
    DrawRegistry::DrawRegistry() {
        if(instance != nullptr) {
            throw std::runtime_error("Il y a deja une instance d'input manager");
        }
        instance = this;
    }

    DrawRegistry::~DrawRegistry() {
        instance = nullptr;
    }

    void DrawRegistry::Draw() const
    {
        for (const IDrawable* drawable : drawables) {
            drawable->Draw();
        }
    }

    void DrawRegistry::RegisterDrawable(IDrawable* drawable)
    {
        drawables.push_back(drawable);
    }

    void DrawRegistry::UnRegisterDrawable(IDrawable* drawable)
    {
        drawables.erase(std::ranges::find(drawables, drawable));
    }

     DrawRegistry& DrawRegistry::Instance() {
        if(!instance) {
            throw std::runtime_error("DrawRegistry hasn't been instanced");
        }
        return *instance;
    }

    DrawRegistry* DrawRegistry::instance = nullptr;
}

