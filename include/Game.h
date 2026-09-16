#pragma once

#include "ProjectilePool.h"
#include "Ship.h"
#include <memory>

#include "EnemyPool.h"
#include "Score.h"

namespace LilShip {

    class Game : public IUpdatable, public IDrawable {
        public:
            Game();
            Game(const Game&) = delete;
            Game(Game&&) noexcept = default;
            ~Game();
            
            Game& operator=(const Game&) = delete;
            Game& operator=(Game&&) = default;
        
            void Draw() const override;
            void Update(float deltaTime) override;

        private:
            std::unique_ptr<Ship> ship;
            ProjectilePool projectilePool;
            std::unique_ptr<EnemyPool> enemyPool;
            Score score;
            int scrolling = 0;
            std::shared_ptr<const Texture> scrollTexture;
    };
}
