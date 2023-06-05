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
#include "Ranger.h"
#include "Knight.h"
#include "Swordsman.h"
#include "Spearman.h"
#include "Game.h"
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

    Game *game = new Game();
    int choice = 1;
    while(choice == 1){
        game->play();
        cout<<"Do you want to play again? (1 for yes, 0 for no)"<<endl;
        cin>>choice;
    }


    return 0;
}




