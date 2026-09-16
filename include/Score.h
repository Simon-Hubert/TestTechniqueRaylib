#pragma once

namespace LilShip{

    class Score
    {
        public:
            Score() = default;
            Score(const Score&) = delete;
            Score(Score&&) = delete;
            ~Score() = default;

            Score& operator=(const Score&) = delete;
            Score& operator=(Score&&) = delete;

        private:
    };
}

