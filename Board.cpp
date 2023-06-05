//
// Created by berke on 2.06.2023.
//

#include "Board.h"
#include <iostream>
#include <iomanip>
#include "Melee.h"
#include "Ranged.h"
#include "Mage.h"
#include "Elf.h"
#include "Bowman.h"
#include "Ranger.h"
#include "Knight.h"
#include "Swordsman.h"
#include "Spearman.h"

using namespace std;

Board::Board() : playerNo(0), health(100) {
    for (int i = 0; i < BOARD_ROWS; ++i) {
        for (int j = 0; j < BOARD_COLUMNS; ++j) {
            board[i][j] = nullptr;
        }
    }
    elfRemaining = 3;
    mageRemaining = 2;
    rangerRemaining = 2;
    knightRemaining = 1;
}

Board::Board(int playerNo, int health) : playerNo(playerNo), health(health) {
    for (int i = 0; i < BOARD_ROWS; ++i) {
        for (int j = 0; j < BOARD_COLUMNS; ++j) {
            board[i][j] = nullptr;
        }
    }
    elfRemaining = 3;
    mageRemaining = 2;
    rangerRemaining = 2;
    knightRemaining = 1;
}

Board::~Board() {
    for (int i = 0; i < BOARD_ROWS; ++i) {
        for (int j = 0; j < BOARD_COLUMNS; ++j) {
            delete board[i][j];
        }
    }
}

void Board::printBoard() {
    cout << "    1       2        3  "<< endl;
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
                cout << setw(CELL_WIDTH) << right << pieceRepresentation << " ║ ";
            }
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

Piece *Board::getCell(int row, int column) {
    //check if the coordinates are valid
    if (row < 0 || row >= BOARD_ROWS || column < 0 || column >= BOARD_COLUMNS) {
        cout << "Invalid coordinates!" << endl;
        return nullptr;
    }
    //return the cell
    return board[row][column];
}

void Board::removeCell(int row, int column) {
    //check if the coordinates are valid
    if (row < 0 || row >= BOARD_ROWS || column < 0 || column >= BOARD_COLUMNS) {
        cout << "Invalid coordinates! You are punished, you can not put a piece this turn." << endl;
        return;
    }
    //check if the cell is empty
    if (board[row][column] == nullptr) {
        cout << "Cell is empty! You are punished, you can not put a piece this turn." << endl;
        return;
    }
    //remove the cell
    board[row][column] = nullptr;
}

int Board::getHealth() const {
    return health;
}

void Board::putPiece() {
    cout<<endl;
    cout<< " It's player " << playerNo << "'s turn" << endl;
    cout<< " Which piece you want to put to the board?" << endl;
    cout<< " 1. Bowman" << endl;
    cout<< " 2. Elf" << endl;
    cout<< " 3. Mage" << endl;
    cout<< " 4. Spearman" << endl;
    cout<< " 5. Ranger " << endl;
    cout<< " 6. Swordsman" << endl;
    cout<< " 7. Knight" << endl;
    cout<< " 8. Abort game" << endl;
    cout<< " Enter your choice: ";
    int choice;
    cin >> choice;
    //check if the choice is valid
    if (choice < 1 || choice > 8) {
        cout << "Invalid choice!" << endl;
        return;
    }
    if(choice == 8)
    {
        cout << "Game aborted!" << endl;
        exit(0);
    }
    //get coordinates from the user
    int row, column;
    cout << "Enter coordinates: (row, column)";
    cin >> row >> column;
    row = row - 1;
    column = column - 1;
    //create the piece
    Piece* piece = nullptr;
    switch (choice) {
        case 1:
            piece = new Bowman();
            if(column == 2)
            {
                cout << "You can not put a bowman to this column! Now you are punished and can not put a piece this turn." << endl;
                return;
            }
            setCell(row, column, piece);
            break;
        case 2:
            piece = new Elf();
            //check if player has any remaining elf pieces to put
            if(elfRemaining <= 0)
            {
                cout << "You don't have any remaining elf pieces to put!" << endl;
                return;
            }
            //if column is 2, elf can not be put
            if(column == 2)
            {
                cout << "You can not put an elf to this column! Now you are punished and can not put a piece this turn." << endl;
                return;
            }
            elfRemaining--;
            setCell(row, column, piece);
            break;
        case 3:
            piece = new Mage();
            //check if player has any remaining mage pieces to put
            if(mageRemaining <= 0)
            {
                cout << "You don't have any remaining mage pieces to put!" << endl;
                return;
            }
            if(column == 2)
            {
                cout << "You can not put a mage to this column! Now you are punished and can not put a piece this turn." << endl;
                return;
            }
            mageRemaining--;
            setCell(row, column, piece);
            break;
        case 4:
            piece = new Spearman();
            if(column == 0)
            {
                cout << "You can not put a spearman to this column! Now you are punished and can not put a piece this turn." << endl;
                return;
            }
            setCell(row, column, piece);
            break;
        case 5:
            piece = new Ranger();
            //check if player has any remaining ranger pieces to put
            if(rangerRemaining <= 0)
            {
                cout << "You don't have any remaining ranger pieces to put!" << endl;
                return;
            }
            if(column == 0)
            {
                cout << "You can not put a ranger to this column! Now you are punished and can not put a piece this turn." << endl;
                return;
            }
            rangerRemaining--;
            setCell(row, column, piece);
            break;
        case 6:
            piece = new Swordsman();
            if(column == 0)
            {
                cout << "You can not put a swordsman to this column! Now you are punished and can not put a piece this turn." << endl;
                return;
            }
            setCell(row, column, piece);
            break;
        case 7:
            piece = new Knight();
            //check if player has any remaining knight pieces to put
            if(knightRemaining <= 0)
            {
                cout << "You don't have any remaining knight pieces to put!" << endl;
                return;
            }
            if(column == 0)
            {
                cout << "You can not put a knight to this column! Now you are punished and can not put a piece this turn." << endl;
                return;
            }
            knightRemaining--;
            setCell(row, column, piece);
            break;
    }
}

void Board::performActions(Board &enemyBoard) {
    putPiece();
    giveBuffs();
    attack(enemyBoard);
}

void Board::giveBuffs() {
    //when
    //the Mage plays a round, it should give a +1 life point bonus to all its teammates on the board,
    //while when the Knight plays a round it gives a +1 attack bonus to all its teammates.
    for(int i = 0; i< 2-mageRemaining ;i++)
    {
     for(int j = 0; j<BOARD_ROWS; j++)
     {
         for(int k = 0; k<BOARD_COLUMNS; k++)
         {
             if(board[j][k] != nullptr)
             {
                 board[j][k]->setHealth(board[j][k]->getHealth()+1);
             }
         }
     }
    }

    if(knightRemaining == 0)
    {
        for(int j = 0; j<BOARD_ROWS; j++)
        {
            for(int k = 0; k<BOARD_COLUMNS; k++)
            {
                if(board[j][k] != nullptr)
                {
                    board[j][k]->setDamage(board[j][k]->getDamage()+1);
                }
            }
        }
    }
}

void Board::attack(Board &enemyBoard) {
    cout << "Player " << playerNo << " is attacking!" << endl;
    //first row
    for(int i=0; i<BOARD_COLUMNS; i++)
    {
        if(board[0][i] != nullptr)
        {
            if(enemyBoard.board[0][0] == nullptr && enemyBoard.board[0][1] == nullptr && enemyBoard.board[0][2] == nullptr)
            {
                enemyBoard.health -= board[0][i]->getDamage();
                continue;
            }
            for(int j=0; j<BOARD_COLUMNS; j++)
            {
                if(enemyBoard.board[0][j] != nullptr)
                {
                    board[0][i]->attack(*enemyBoard.board[0][j]);
                    if(enemyBoard.board[0][j]->getHealth() <= 0)
                    {
                        enemyBoard.removeCell(0, j);
                    }
                    break;
                }
            }
        }
    }
    //second row
    for(int i=0; i<BOARD_COLUMNS; i++)
    {
        if(board[1][i] != nullptr)
        {
            if(enemyBoard.board[1][0] == nullptr && enemyBoard.board[1][1] == nullptr && enemyBoard.board[1][2] == nullptr)
            {
                enemyBoard.health -= board[1][i]->getDamage();
                continue;
            }
            for(int j=0; j<BOARD_COLUMNS; j++)
            {
                if(enemyBoard.board[1][j] != nullptr)
                {
                    board[1][i]->attack(*enemyBoard.board[1][j]);
                    if(enemyBoard.board[1][j]->getHealth() <= 0)
                    {
                        enemyBoard.removeCell(1, j);
                    }
                    break;
                }
            }
        }
    }
    //third row
    for(int i=0; i<BOARD_COLUMNS; i++)
    {
        if(board[2][i] != nullptr)
        {
            if(enemyBoard.board[2][0] == nullptr && enemyBoard.board[2][1] == nullptr && enemyBoard.board[2][2] == nullptr)
            {
                enemyBoard.health -= board[2][i]->getDamage();
                continue;
            }
            for(int j=0; j<BOARD_COLUMNS; j++)
            {
                if(enemyBoard.board[2][j] != nullptr)
                {
                    board[2][i]->attack(*enemyBoard.board[2][j]);
                    if(enemyBoard.board[2][j]->getHealth() <= 0)
                    {
                        enemyBoard.removeCell(2, j);
                    }
                    break;
                }
            }
        }
    }
    //fourth row
    for(int i=0; i<BOARD_COLUMNS; i++)
    {
        if(board[3][i] != nullptr)
        {
            if(enemyBoard.board[3][0] == nullptr && enemyBoard.board[3][1] == nullptr && enemyBoard.board[3][2] == nullptr)
            {
                enemyBoard.health -= board[3][i]->getDamage();
                continue;
            }
            for(int j=0; j<BOARD_COLUMNS; j++)
            {
                if(enemyBoard.board[3][j] != nullptr)
                {
                    board[3][i]->attack(*enemyBoard.board[3][j]);
                    if(enemyBoard.board[3][j]->getHealth() <= 0)
                    {
                        enemyBoard.removeCell(3, j);
                    }
                    break;
                }
            }
        }
    }

}




