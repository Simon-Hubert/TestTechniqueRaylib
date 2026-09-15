#include <UpdateRegistry.h>
#include <algorithm>
#include <stdexcept>
#include <iostream>

namespace LilShip{
    UpdateRegistry::UpdateRegistry() {
        if(instance != nullptr) {
            throw std::runtime_error("Il y a deja une instance d'input manager");
        }
        instance = this;
    }

    UpdateRegistry::~UpdateRegistry() {
        instance = nullptr;
    }

    void UpdateRegistry::Update(float detlaTime)
    {
        for (IUpdatable* updatable : updatables) {
            updatable->Update(detlaTime);
        }
    }

    void UpdateRegistry::RegisterUpdatable(IUpdatable* updatable)
    {
        updatables.push_back(updatable);
    }

    void UpdateRegistry::UnRegisterUpdatable(IUpdatable* updatable)
    {
        updatables.erase(std::find(updatables.begin(), updatables.end(), updatable));
    }

    UpdateRegistry& UpdateRegistry::Instance() {
        if(!instance) {
            throw std::runtime_error("UpdateRegistry hasn't been instanced");
        }
        return *instance;
    }

    UpdateRegistry* UpdateRegistry::instance = nullptr;
}

