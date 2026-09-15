#include <InputManager.h>
#include <stdexcept>

namespace LilShip{
    InputManager::InputManager() {
        if(instance != nullptr) {
            throw std::runtime_error("Il y a deja une instance d'input manager");
        }
        instance = this;
    }

    InputManager::~InputManager() {
        instance = nullptr;
    }
    
    void InputManager::BindKey(KeyboardKey key, std::string action)
    {
        if(!action.empty()) {
            keyboardBinding[key] = std::move(action);
        }
        else {
            keyboardBinding.erase(key);
        }
    }

    void InputManager::BindAction(const std::string& action, std::function<void(KeyState)> func)
    {
        actionMap[action] = std::move(func);
    }

    void InputManager::Update()
    {
        for(const auto& [key, action] : keyboardBinding) {
            if(IsKeyPressed(key)) {
                TriggerAction(action, PRESSED);
            }
            if(IsKeyReleased(key)) {
                TriggerAction(action, RELEASED);
            }
            if(IsKeyDown(key)) {
                TriggerAction(action, PERFORMED);
            }
            
        }
    }
    
    InputManager& InputManager::Instance() {
        if(!instance) {
            throw std::runtime_error("InputManager hasn't been instanced");
        }
        return *instance;
    }

    void InputManager::TriggerAction(const std::string& action, KeyState state)
    {
        auto it = actionMap.find(action);
        if(it == actionMap.end()) {
            return;
        }
        it->second(state);
    }

    InputManager* InputManager::instance = nullptr;
}
