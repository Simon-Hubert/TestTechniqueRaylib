#include <EnemyPool.h>
#include <memory>
#include <stdexcept>

namespace LilShip{

    EnemyPool::EnemyPool() {
        if(instance != nullptr) {
            throw std::runtime_error("Il y a deja une instance d'input manager");
        }
        instance = this;
        
        enemyTexture = std::make_shared<const Texture>("resources/newAssetPack/Test One0001.png");
        UpdateRegistry::Instance().RegisterUpdatable(instance);
    }

    EnemyPool::~EnemyPool() {
        UpdateRegistry::Instance().UnRegisterUpdatable(instance);
        instance = nullptr;
    }

    EnemyPool& EnemyPool::Instance() {
        if(!instance) {
            throw std::runtime_error("ProjectilePool hasn't been instanced");
        }
        return *instance;
    }

    EnemyPool* EnemyPool::instance = nullptr;

    std::shared_ptr<Enemy> EnemyPool::SpawnEnemy(){
        if(!enemyPool.empty()){
            std::shared_ptr<Enemy> enemy = enemyPool.back();
            enemyPool.pop_back();
            activeEnemies.push_back(enemy);
            enemy->Spawn({850, 300});
            return enemy;
        }
        else{
            std::shared_ptr<Enemy> enemy = std::make_shared<Enemy>(enemyTexture, nextId++);
            activeEnemies.push_back(enemy);
            enemy->Spawn({850, 300});
            return enemy;
        }
    }

    void EnemyPool::Update(float deltaTime)
    {
        if(cooldown < 0) {
            SpawnEnemy();
            cooldown = 3.f;
        }
        cooldown -= deltaTime;
    }

    const std::vector<std::shared_ptr<Enemy>>* EnemyPool::GetActiveEnemies() const
    {
        return &activeEnemies;
    }

    void EnemyPool::ReturnEnemy(int id){
        for (auto it = activeEnemies.begin(); it != activeEnemies.end(); ++it)
        {
            if ((*it)->id == id)
            {
                enemyPool.push_back(std::move(*it));
                activeEnemies.erase(it);
                return;
            }
        }
    }
}
