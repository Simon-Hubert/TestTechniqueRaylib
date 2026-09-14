#include "Game.h"
#include "Texture.h"
#include "raylib.h"
#include <memory>

namespace LilShip {
    Game::Game()
    {
        std::shared_ptr<const Texture> shipTexture = std::make_shared<const Texture>("resources/newAssetPack/000.png");
        ship = std::make_unique<Ship>(shipTexture);
        shipTex = LoadTexture("resources/newAssetPack/Mountain.png");
    }

    Game::~Game()
    {
        UnloadTexture(shipTex);
    }

    void Game::Update(float deltaTime)
    {
        ship->Update(deltaTime);
    }

    void Game::Draw()
    {
        ship->Draw();
        DrawTextureEx(shipTex, {200,200}, 0, 1, WHITE);
    }
}
