#pragma once

namespace LilShip{

    class Score
    {
        public:
            Score();
            Score(const Score&) = delete;
            Score(Score&&) = delete;
            ~Score();

            Score& operator=(const Score&) = delete;
            Score& operator=(Score&&) = delete;
        
            static Score& Instance();
            
            void Add(int value);
            int Get() const;

        private:
            int _score = 0;
            static Score* instance;
        
    };
}

