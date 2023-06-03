//
// Created by berke on 2.06.2023.
//

#ifndef HEROES_OF_THE_BOARD_BOARD_H
#define HEROES_OF_THE_BOARD_BOARD_H
#include <iostream>
#include "Piece.h"

const int BOARD_ROWS = 4;
const int BOARD_COLUMNS = 3;
const int CELL_WIDTH = 5;

class Board {
private:
    Piece* board[BOARD_ROWS][BOARD_COLUMNS];
    int playerNo;
    int health;

public:
    Board();
    Board(int playerNo, int health);
    ~Board();
    void printBoard();
    bool isCellEmpty(int row, int column);
    void setCell(int row, int column, Piece* piece);
    int getHealth() const;
    void setHealth(int health);
};


#endif //HEROES_OF_THE_BOARD_BOARD_H
