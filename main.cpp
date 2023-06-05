/*
 * Berke Diler - 2401503
 * I read and accept the submission rules and the important section
 * specified in assignment file. This is my own work that is done by myself
 * and my team-mate only.
*/
#include <iostream>
#include "Board.h"
#include "Melee.h"
#include "Ranged.h"
#include "Mage.h"
#include "Elf.h"
#include "Bowman.h"
#include <windows.h>

using namespace std;

int main()
{
    SetConsoleOutputCP( 65001 ); //Used for printing UTF-8 characters
    std::cout << R"(
  _   _                                   __   _   _           ______                     _
 | | | |                                 / _| | | | |          | ___ \                   | |
 | |_| | ___ _ __ ___   ___  ___    ___ | |_  | |_| |__   ___  | |_/ / ___   __ _ _ __ __| |
 |  _  |/ _ \ '__/ _ \ / _ \/ __|  / _ \|  _| | __| '_ \ / _ \ | ___ \/ _ \ / _` | '__/ _` |
 | | | |  __/ | | (_) |  __/\__ \ | (_) | |   | |_| | | |  __/ | |_/ / (_) | (_| | | | (_| |
 \_| |_/\___|_|  \___/ \___||___/  \___/|_|    \__|_| |_|\___| \____/ \___/ \__,_|_|  \__,_|
A legendary board game where you can play with your friends and have fun!
-Made by Berke Diler and Bedirhan Ozkan

)" << std::endl;

    Board *board1 = new Board(1, 100);

    Piece *mage1 = new Mage();
    Piece *bowman1 = new Bowman();
    Piece *elf1 = new Elf();

    board1->setCell(0, 0, mage1);
    board1->setCell(0, 1, bowman1);
    board1->setCell(0, 2, elf1);


    board1->printBoard();
    board1->printReverseBoard();



    return 0;
}




