/***************************************************************************
 *
 * Copyright © 2016 LT. All Rights Reserved.
 *
 ***************************************************************************/

/**
 *
 * @file: game.h
 *
 * @breaf: 
 *
 * @author: Lei Yunfei(towardstheway@gmail.com)
 *
 * @create: 2018/03/24 18时16分29秒
 *
 **/

#ifndef  GAME_INC
#define  GAME_INC

#include <iostream>
#include <cassert>
#include <ctime>


class Game {
public:
    Game() : player_count_(0), moves_count_(0), player_won_(-1) {
        std::srand((unsigned)time(NULL));
    }

    virtual ~Game() {}

    void PlayOneGame(const int player_count = 0) {
        if (player_count) {
            this->player_count_ = player_count;
        }

        InitializeGame();
        assert(this->player_count_);

        int j = 0;
        while (!EndOfGame()) {
            MakePlay(j);
            j = (j+1) % this->player_count_;
            if (j != 0) {
                ++moves_count_;
            }
        }
        PrintWinner();
    }

protected:
    virtual void InitializeGame() = 0;
    virtual void EndOfGame() = 0;
    virtual void MakePlay(int player) = 0;
    virtual void PrintWinner() = 0;

private:
    int player_count_;
    int moves_count_;
    int player_won_;
};

#endif   // ----- #ifndef GAME_INC  -----
