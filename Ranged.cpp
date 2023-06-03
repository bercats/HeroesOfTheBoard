//
// Created by berke on 3.06.2023.
//

#include "Ranged.h"
#include <iostream>

Ranged::Ranged(int health, int damage, char *character) : Piece(health, damage, character) {}

void Ranged::attack() {
    std::cout << "Ranged attack" << std::endl;
}

void Ranged::print() {
    std::cout << character << "[" << health << "]" << std::endl;
}