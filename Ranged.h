//
// Created by berke on 3.06.2023.
//

#ifndef HEROESOFTHEBOARD_RANGED_H
#define HEROESOFTHEBOARD_RANGED_H
#include "Piece.h"

class Ranged : public Piece{
public:
    Ranged(int health, int damage, char* character);

    void attack() override;

    void print() override;

};


#endif //HEROESOFTHEBOARD_RANGED_H
