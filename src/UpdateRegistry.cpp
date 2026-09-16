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
        HandlePending();
        
        for (IUpdatable* updatable : updatables) {
            if(!updatable) continue;
            updatable->Update(detlaTime);
        }
    }

    void UpdateRegistry::RegisterUpdatable(IUpdatable* updatable)
    {
        pendingAdd.push(updatable);
        //updatables.push_back(updatable);
    }

    void UpdateRegistry::UnRegisterUpdatable(IUpdatable* updatable)
    {
        pendingRemove.push(updatable);
        //updatables.erase(std::find(updatables.begin(), updatables.end(), updatable));
    }

    void UpdateRegistry::HandlePending()
    {
        while(!pendingAdd.empty()) {
            updatables.push_back(pendingAdd.front());
            pendingAdd.pop();
        }
        
        while(!pendingRemove.empty()) {
            updatables.erase(std::find(updatables.begin(), updatables.end(), pendingRemove.front()));
            pendingRemove.pop();
        }
    }

    UpdateRegistry& UpdateRegistry::Instance() {
        if(!instance) {
            throw std::runtime_error("UpdateRegistry hasn't been instanced");
        }
        return *instance;
    }

    UpdateRegistry* UpdateRegistry::instance = nullptr;
}

