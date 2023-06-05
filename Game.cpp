//
// Created by berke on 5.06.2023.
//

#include <ctime>
#include "Game.h"
#include <iostream>


using namespace std;

Game::Game() {
    player1 = new Board(1, 100);
    player2 = new Board(2, 100);
    srand(time(NULL));
    turn = rand() % 2 + 1;
    player1Score = 0;
    player2Score = 0;
}

Game::~Game() {
    delete player1;
    delete player2;
}

void Game::playTurn() {
    if(turn == 1)
    {
        player1->performActions(*player2);
        player1->printBoard();
        player2->printBoard();
    }
    else
    {
        player2->performActions(*player1);
        player1->printBoard();
        player2->printBoard();
    }
}

void Game::switchTurn() {
    //randomly switch turn
    turn = rand() % 2 + 1;
}

bool Game::isGameOver() {
    if(player1->getHealth() <= 0 || player2->getHealth() <= 0)
    {
        return true;
    }
    return false;
}

void Game::play() {
    while(!isGameOver())
    {
        playTurn();
        switchTurn();
    }
    cout<<"Game Over"<<endl;
    if(player1->getHealth() <= 0)
    {
        cout<<"Player 2 won the game"<<endl;
        player2Score++;
    }
    else
    {
        cout<<"Player 1 won the game"<<endl;
        player1Score++;
    }
    cout<<"Player 1 Score: "<<player1Score<<endl;
    cout<<"Player 2 Score: "<<player2Score<<endl;
}
