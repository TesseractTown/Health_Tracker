#pragma once
#include <string>

class playerCharacter {
public:
    std::string name;
    int mag;
    int end;
    int mana;
    int addMana;
    int subMana;
    int health{ 0 };
    Injuries injuries{ Injuries(5) };
    bool isDead{ false };

	//Set PC Stats
    playerCharacter();
    void setName();
    std::string getName() { return name; };
    void setHealth();
    void setMag();
	void takeDamage();
	void Fheal();
	void FaddMana();
	void subtractMana();


};
