#pragma once

#include <memory>
#include <vector>

#include "Enemy.h"
#include "Texture.h"

namespace LilShip{

    class EnemyPool : public IUpdatable
    {
        friend Enemy;
        
        public:
            EnemyPool();
            EnemyPool(const EnemyPool&) = delete;
            EnemyPool(EnemyPool&&) = delete;
            ~EnemyPool();

            EnemyPool& operator=(const EnemyPool&) = delete;
            EnemyPool& operator=(EnemyPool&&) = delete;
        

        static EnemyPool& Instance();

            std::shared_ptr<Enemy> SpawnEnemy();
            void Update(float deltaTime) override;
        
            const std::vector<std::shared_ptr<Enemy>>* GetActiveEnemies() const;
        
        private:
            int nextId = 0;
            
            void ReturnEnemy(int id);
            static EnemyPool* instance;
            std::vector<std::shared_ptr<Enemy>> enemyPool;
            std::vector<std::shared_ptr<Enemy>> activeEnemies;
            std::shared_ptr<const Texture> enemyTexture;
        
            float cooldown = 0;
    };
}

