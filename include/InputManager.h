#pragma once

#include <unordered_map>
#include <string>
#include <functional>
#include "raylib.h"

namespace LilShip{
    enum KeyState
    {
        PRESSED,
        RELEASED,
        PERFORMED
    };
    
    class InputManager
    {
        public:
            InputManager();
            InputManager(const InputManager&) = delete;
            InputManager(InputManager&&) = delete;
            ~InputManager();

            InputManager& operator=(const InputManager&) = delete;
            InputManager& operator=(InputManager&&) = delete;
        
            void BindKey(KeyboardKey key, std::string action);
            void BindAction(const std::string& action, std::function<void(KeyState)> func);
        
            void Update();
            static InputManager& Instance();

        private:
            void TriggerAction(const std::string& action, KeyState state);
            
            std::unordered_map<std::string, std::function<void(KeyState)>> actionMap;
            std::unordered_map<KeyboardKey, std::string> keyboardBinding;
            static InputManager* instance;
    };
}

