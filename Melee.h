//
// Created by berke on 3.06.2023.
//

#ifndef HEROESOFTHEBOARD_MELEE_H
#define HEROESOFTHEBOARD_MELEE_H
#include "Piece.h"

class Melee : public Piece{
public:
    Melee(int health, int damage, char* character);

    void attack() override;

    void print() override;
};


#endif //HEROESOFTHEBOARD_MELEE_H
