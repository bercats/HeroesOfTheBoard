//
// Created by berke on 3.06.2023.
//

#include "Piece.h"

Piece::Piece(int health, int damage, char *character) : health(health), damage(damage), character(character){}

int Piece::getHealth() const {
    return health;
}

void Piece::setHealth(int health) {
    Piece::health = health;
}

int Piece::getDamage() const {
    return damage;
}

void Piece::setDamage(int damage) {
    Piece::damage = damage;
}

char *Piece::getCharacter() const {
    return character;
}

void Piece::setCharacter(char *character) {
    Piece::character = character;
}

Piece::~Piece() {
    delete character;
}


