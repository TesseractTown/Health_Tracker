#include "Injuries.h"
#include "playerCharacter.h"
#include <iostream>
using namespace std;

playerCharacter::playerCharacter() {
	setName();
	setHealth();
	setMag();

}

void playerCharacter::setName() {
	char* input_name = new char[100];
	cout << "What is your characters name?\n";
	cin >> input_name;
	cout << "\n";
	name = input_name;
	//return name;
}

void playerCharacter::setHealth() {
	cout << "What is END parameter?\n";
	cin >> end;
	cout << "\n";
	end = end;
	injuries = Injuries(end);
	switch (end)
	{
	case 0:
		health = 10;
		break;
	case 1:
		health = 20;
		break;
	case 2:
		health = 40;
		break;
	case 3:
		health = 60;
		break;
	case 4:
		health = 80;
		break;
	case 5:
		health = 100;
		break;
	}
	//return health;
}

void playerCharacter::setMag() {
	int mag;
	cout << "What is your Mag parameter?\n";
	cin >> mag;
	cout << "\n";
	switch (mag)
	{
	case 0:
		mana = 0;
		break;
	case 1:
		mana = 20;
		break;
	case 2:
		mana = 40;
		break;
	case 3:
		mana = 60;
		break;
	case 4:
		mana = 80;
		break;
	case 5:
		mana = 100;
		break;
	}
	//return mana;
}

void playerCharacter::takeDamage() {
	int damage;
	cout << "----------------------" << '\n';
	cout << "How Much Damage?\n";
	cin >> damage;
	health = health - damage;
	if (health <= 0) {
		isDead = true;
		health = 0;
	};
	cout << "\n" << '\n';
}

void playerCharacter::Fheal() {
	int heal;
	cout << "----------------------" << '\n';
	cout << "How much heals you get?\n";
	cin >> heal;
	health = health + heal;
	cout << "\n" << '\n';
}

void playerCharacter::FaddMana() {
	int addMana;
	cout << "----------------------" << '\n';
	cout << "Mana Gained?\n";
	cin >> addMana;
	mana = addMana + mana;
	cout << "Current Mana: ";
	cout << mana;
	cout << '\n' << '\n';
}

void playerCharacter::subtractMana() {
	int subMana;
	cout << "----------------------" << '\n';
	cout << "Mana Used?\n";
	cin >> subMana;
	mana = mana - subMana;
	cout << "Current Mana: ";
	cout << mana;
	cout << '\n' << '\n';
}





//class playerCharacter::playerCharacter {
//public:
//
//    //Set PC Stats
//    playerCharacter() {
//
//    }
//
//    string setName() {
//        cout << "What is your characters name?\n";
//        cin >> name;
//        cout << "\n";
//        name = name;
//        return name;
//    }
//
//    int setHealth() {
//        cout << "What is END parameter?\n";
//        cin >> end;
//        cout << "\n";
//        end = end;
//        injuries = Injuries(end);
//        switch (end)
//        {
//        case 0:
//            health = 10;
//            break;
//        case 1:
//            health = 20;
//            break;
//        case 2:
//            health = 40;
//            break;
//        case 3:
//            health = 60;
//            break;
//        case 4:
//            health = 80;
//            break;
//        case 5:
//            health = 100;
//            break;
//        }
//        return health;
//    }
//
//    int setMag() {
//        cout << "What is your Mag parameter?\n";
//        cin >> mag;
//        cout << "\n";
//        mag = mag;
//        switch (mag)
//        {
//        case 0:
//            mana = 0;
//            break;
//        case 1:
//            mana = 20;
//            break;
//        case 2:
//            mana = 40;
//            break;
//        case 3:
//            mana = 60;
//            break;
//        case 4:
//            mana = 80;
//            break;
//        case 5:
//            mana = 100;
//            break;
//        }
//        return mana;
//
//    }
//
//    //PC functions
//
//    void takeDamage() {
//        int damage;
//        cout << "----------------------" << '\n';
//        cout << "How Much Damage?\n";
//        cin >> damage;
//        health = health - damage;
//        if (health <= 0) {
//            isDead = true;
//            health = 0;
//        };
//        cout << "\n" << '\n';
//    }
//
//    void Fheal() {
//        int heal;
//        cout << "----------------------" << '\n';
//        cout << "How much heals you get?\n";
//        cin >> heal;
//        health = health + heal;
//        cout << "\n" << '\n';
//    }
//
//    void FaddMana() {
//		int addMana;
//        cout << "----------------------" << '\n';
//        cout << "Mana Gained?\n";
//        cin >> addMana;
//        mana = addMana + mana;
//        cout << "Current Mana: ";
//        cout << mana;
//        cout << '\n' << '\n';
//    }
//
//    void subtractMana() {
//		int subMana;
//        cout << "----------------------" << '\n';
//        cout << "Mana Used?\n";
//        cin >> subMana;
//        mana = mana - subMana;
//        cout << "Current Mana: ";
//        cout << mana;
//        cout << '\n' << '\n';
//    }
//
//};