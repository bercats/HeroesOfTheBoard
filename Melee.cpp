//
// Created by berke on 3.06.2023.
//

#include "Melee.h"
#include <iostream>

Melee::Melee(int health, int damage, char *character) : Piece(health, damage, character) {}

void Melee::attack() {
    std::cout << "Melee attack" << std::endl;
}

void Melee::print() {
    std::cout << character << "[" << health << "]" << std::endl;
}