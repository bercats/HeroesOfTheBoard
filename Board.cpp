//
// Created by berke on 2.06.2023.
//

#include "Board.h"
#include <iostream>
#include <iomanip>

using namespace std;

Board::Board() : playerNo(0), health(100) {
    for (int i = 0; i < BOARD_ROWS; ++i) {
        for (int j = 0; j < BOARD_COLUMNS; ++j) {
            board[i][j] = nullptr;

        }
    }
}

Board::Board(int playerNo, int health) : playerNo(playerNo), health(health) {
    for (int i = 0; i < BOARD_ROWS; ++i) {
        for (int j = 0; j < BOARD_COLUMNS; ++j) {
            board[i][j] = nullptr;
        }
    }
}


void Board::printBoard() {
    cout << "╔═══════╦═══════╦═══════╗" << endl;
    for (int i = 0; i < BOARD_ROWS; i++) {
        cout << "║ ";
        for (int j = 0; j < BOARD_COLUMNS; j++) {
            if(board[i][j] == nullptr)
            {
                cout << std::setw(CELL_WIDTH)  << " " << " ║ ";
            }
            else {
                string character = board[i][j]->getCharacter();
                string health = to_string(board[i][j]->getHealth());
                string pieceRepresentation = character + "[" + health + "]";
                cout << setw(CELL_WIDTH) << right << pieceRepresentation << " ║ ";            }
        }
        cout << endl;
        if (i != BOARD_ROWS - 1) {
            cout << "╠═══════╬═══════╬═══════╣" << endl;
        }
    }
    cout << "╚═══════╩═══════╩═══════╝" << endl;
    cout<<"Player No: "<<playerNo<<endl;
    cout<<"Health: "<<health<<endl;
}

bool Board::isCellEmpty(int row, int column) {
    //check if the coordinates are valid
    if (row < 0 || row >= BOARD_ROWS || column < 0 || column >= BOARD_COLUMNS) {
        cout << "Invalid coordinates!" << endl;
        return false;
    }

    //check if the cell is empty
    if (board[row][column] != nullptr) {
        cout << "Cell is not empty!" << endl;
        return false;
    }

    return true;
}

void Board::setCell(int row, int column, Piece* piece) {
    //check if the coordinates are valid
    if (row < 0 || row >= BOARD_ROWS || column < 0 || column >= BOARD_COLUMNS) {
        cout << "Invalid coordinates!" << endl;
        return;
    }

    //check if the cell is empty
    if (!isCellEmpty(row, column)) {
        cout << "Cell is not empty!" << endl;
        return;
    }

    //set the cell
    board[row][column] = piece;
}



