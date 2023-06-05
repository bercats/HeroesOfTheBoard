//
// Created by berke on 3.06.2023.
//

#ifndef HEROESOFTHEBOARD_PIECE_H
#define HEROESOFTHEBOARD_PIECE_H


class Piece {
protected:
    int health;
    int damage;
    char* character;

public:
    Piece(int health, int damage, char* character);

    virtual ~Piece();

    int getHealth() const;

    void setHealth(int health);

    int getDamage() const;

    void setDamage(int damage);

    char *getCharacter() const;

    void setCharacter(char *character);

    virtual void attack(Piece &target);

    virtual void print() = 0;
};;


#endif //HEROESOFTHEBOARD_PIECE_H
