#pragma once

#include <vector>

namespace LilShip{

    class IUpdatable{
        public:
            virtual void Update(float deltaTime) = 0;
    };

    class UpdateRegistry
    {
        public:
            UpdateRegistry();
            UpdateRegistry(const UpdateRegistry&) = delete;
            UpdateRegistry(UpdateRegistry&&) = delete;
            ~UpdateRegistry();

            UpdateRegistry& operator=(const UpdateRegistry&) = delete;
            UpdateRegistry& operator=(UpdateRegistry&&) = delete;

            static UpdateRegistry& Instance();

            void Update(float detlaTime);
            void RegisterUpdatable(IUpdatable* updatable);
            void UnRegisterUpdatable(IUpdatable* updatable);

        private:
            std::vector<IUpdatable*> updatables;
            static UpdateRegistry* instance;
    };
}

