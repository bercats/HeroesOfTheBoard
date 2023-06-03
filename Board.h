//
// Created by berke on 2.06.2023.
//

#ifndef HEROES_OF_THE_BOARD_BOARD_H
#define HEROES_OF_THE_BOARD_BOARD_H
#include <iostream>

const int BOARD_ROWS = 4;
const int BOARD_COLUMNS = 3;
const int CELL_WIDTH = 15;

class Board {
private:
    char board[BOARD_ROWS][BOARD_COLUMNS];

public:
    Board();
    void printBoard();
    bool isCellEmpty(int row, int column);
    void setCell(int row, int column, char piece);
};


#endif //HEROES_OF_THE_BOARD_BOARD_H
