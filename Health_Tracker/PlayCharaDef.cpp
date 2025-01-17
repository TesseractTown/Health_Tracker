#include "Injuries.h"
#include "PlayerChar.h"
#include <iostream>
using namespace std;

class playerCharacter {
public:
    int mag;
    int end;
    int mana;
    int addMana;
    int subMana;
    int health{ 0 };
    Injuries injuries{ Injuries(5) };
    string name;
    bool isDead{ false };

    //Set PC Stats
    playerCharacter() {

    }

    string setName() {
        cout << "What is your characters name?\n";
        cin >> name;
        cout << "\n";
        this->name = name;
        return name;
    }

    int setHealth() {
        cout << "What is END parameter?\n";
        cin >> end;
        cout << "\n";
        this->end = end;
        this->injuries = Injuries(end);
        switch (end)
        {
        case 0:
            this->health = 10;
            break;
        case 1:
            this->health = 20;
            break;
        case 2:
            this->health = 40;
            break;
        case 3:
            this->health = 60;
            break;
        case 4:
            this->health = 80;
            break;
        case 5:
            this->health = 100;
            break;
        }
        return health;
    }

    int setMag() {
        cout << "What is your Mag parameter?\n";
        cin >> mag;
        cout << "\n";
        this->mag = mag;
        switch (mag)
        {
        case 0:
            this->mana = 0;
            break;
        case 1:
            this->mana = 20;
            break;
        case 2:
            this->mana = 40;
            break;
        case 3:
            this->mana = 60;
            break;
        case 4:
            this->mana = 80;
            break;
        case 5:
            this->mana = 100;
            break;
        }
        return mana;

    }

    //PC functions

    void takeDamage() {
        cout << "----------------------" << '\n';
        cout << "How Much Damage?\n";
        cin >> damage;
        this->health = this->health - damage;
        if (this->health <= 0) {
            this->isDead = true;
            this->health = 0;
        };
        cout << "\n" << '\n';
    }

    void Fheal() {
        cout << "----------------------" << '\n';
        cout << "How much heals you get?\n";
        cin >> heal;
        this->health = this->health + heal;
        cout << "\n" << '\n';
    }

    void FaddMana() {
        cout << "----------------------" << '\n';
        cout << "Mana Gained?\n";
        cin >> addMana;
        this->mana = this->addMana + mana;
        cout << "Current Mana: ";
        cout << this->mana;
        cout << '\n' << '\n';
    }

    void subtractMana() {
        cout << "----------------------" << '\n';
        cout << "Mana Used?\n";
        cin >> subMana;
        this->mana = this->mana - subMana;
        cout << "Current Mana: ";
        cout << this->mana;
        cout << '\n' << '\n';
    }

};