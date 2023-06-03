//
// Created by berke on 2.06.2023.
//

#include "Board.h"
#include <iostream>

using namespace std;

Board::Board() {
    for (int i = 0; i < BOARD_ROWS; ++i) {
        for (int j = 0; j < BOARD_COLUMNS; ++j) {
            board[i][j] = ' ';
        }
    }
}

void Board::printBoard() {
    std::cout << "╔═══╦═══╦═══╗" << std::endl;
    for (int i = 0; i < BOARD_ROWS; i++) {
        std::cout << "║ ";
        for (int j = 0; j < BOARD_COLUMNS; j++) {
            std::cout << board[i][j] << " ║ ";
        }
        std::cout << std::endl;
        if (i != BOARD_ROWS - 1) {
            std::cout << "╠═══╬═══╬═══╣" << std::endl;
        }
    }
    std::cout << "╚═══╩═══╩═══╝" << std::endl;
}

bool Board::isCellEmpty(int row, int column) {
    return board[row][column] == ' ';
}

void Board::setCell(int row, int column, char piece) {
    board[row][column] = piece;
}

