//
// Created by berke on 5.06.2023.
//

#ifndef HEROESOFTHEBOARD_GAME_H
#define HEROESOFTHEBOARD_GAME_H


#include "Board.h"
#include "Melee.h"
#include "Ranged.h"
#include "Mage.h"
#include "Elf.h"
#include "Bowman.h"
#include "Ranger.h"
#include "Knight.h"
#include "Swordsman.h"
#include "Spearman.h"

class Game {
private:
    Board *player1;
    Board *player2;
    int turn; //turn to be decided randomly, 1 for player1, 2 for player2
    int player1Score;
    int player2Score;

public:
    Game();
    ~Game();
    void playTurn();
    void switchTurn();
    bool isGameOver();
    void play();


};


#endif //HEROESOFTHEBOARD_GAME_H
