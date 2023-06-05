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
    int elfRemaining;
    int mageRemaining;
    int rangerRemaining;
    int knightRemaining;

public:
    Board();
    Board(int playerNo, int health);
    ~Board();
    void printBoard();
    bool isCellEmpty(int row, int column);
    void setCell(int row, int column, Piece* piece);
    Piece* getCell(int row, int column);
    void removeCell(int row, int column);
    int getHealth() const;
    void setHealth(int health);
    void putPiece();
    void performActions(Board &enemyBoard);
    void attack(Board &enemyBoard);
    void giveBuffs();
};


#endif //HEROES_OF_THE_BOARD_BOARD_H
