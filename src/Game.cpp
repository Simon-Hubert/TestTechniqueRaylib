#include "Game.h"
#include "Texture.h"
#include "raylib.h"
#include <memory>

namespace LilShip {
    Game::Game()
    {
        std::shared_ptr<const Texture> shipTexture = std::make_shared<const Texture>("resources/newAssetPack/000.png");
        ship = std::make_unique<Ship>((Vector2){200, 200}, 25.f, shipTexture);
    }

    Game::~Game()
    {
    }
}
