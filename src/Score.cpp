#include <Score.h>
#include <stdexcept>

namespace LilShip{
    Score::Score() {
        if(instance != nullptr) {
            throw std::runtime_error("Il y a deja une instance d'input manager");
        }
        instance = this;
    }

    Score::~Score() {
        instance = nullptr;
    }

    Score& Score::Instance()
    {
        return *instance;
    }

    void Score::Add(int value)
    {
        _score += value;
    }

    int Score::Get() const
    {
        return _score;
    }

    Score* Score::instance = nullptr;
    
}
