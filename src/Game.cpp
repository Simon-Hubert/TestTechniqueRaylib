#include "Game.h"
#include "Texture.h"
#include "raylib.h"
#include <memory>

namespace LilShip {
    Game::Game()
    {
        DrawRegistry::Instance().RegisterDrawable(this);
        UpdateRegistry::Instance().RegisterUpdatable(this);
        std::shared_ptr<const Texture> shipTexture = std::make_shared<const Texture>("resources/newAssetPack/000.png");
        scrollTexture = std::make_shared<const Texture>("resources/newAssetPack/Space Attempt 1_stars2.png");
        ship = std::make_unique<Ship>(Vector2{200, 200}, 25.f, shipTexture);
    }

    Game::~Game()
    {
        DrawRegistry::Instance().UnRegisterDrawable(this);
        UpdateRegistry::Instance().UnRegisterUpdatable(this);
    }

    void Game::Draw() const
    {
        scrollTexture->Draw({(float)scrolling, 0}, 0, 4);
        scrollTexture->Draw({(float)scrolling + scrollTexture->GetSize().x * 4, 0}, 0, 4);
    }

    void Game::Update(float deltaTime)
    {
        scrolling -= 8;
        if(scrolling <= -scrollTexture->GetSize().x * 4) scrolling = 0;
    }
}
