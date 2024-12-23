#include <iostream>
#include <map>
using namespace std;

//Add Injuries
//default constrrtuctors for initalize playerCharacter?

int damage;
int heal;
int choice;
string input;

class Injuries {
public:

    int maxMinor;
    int maxModerate;
    int maxSevere;
    int currMinor{ 0 };
    int currModerate{ 0 };
    int currSevere{ 0 };
    int currCritical{ 0 };

    //constructor

    Injuries(int end) {
        setInjuries(end);
    }

    //functions

    void getTotalInjuries() {
        cout << "Minor: " << currMinor << '\n';
        cout << "Moderate: " << currModerate << '\n';
        cout << "Severe: " << currSevere << '\n';
        cout << "Critical: " << currCritical << '\n';
    }

    int getInjuryPenalty() {};
    void addInjury(int inflictedInjuries) {};

    void setInjuries(int end) {
        switch (end) {
        case 0:
            maxMinor = 1;
            maxModerate = 1;
            maxSevere = 0;
            break;
        case 1:
            maxMinor = 1;
            maxModerate = 1;
            maxSevere = 1;
            break;
        case 2:
            maxMinor = 2;
            maxModerate = 1;
            maxSevere = 1;
            break;
        case 3:
            maxMinor = 3;
            maxModerate = 2;
            maxSevere = 1;
            break;
        case 4:
            maxMinor = 4;
            maxModerate = 2;
            maxSevere = 1;
            break;
        case 5:
            maxMinor = 5;
            maxModerate = 3;
            maxSevere = 2;
            break;
        }
    }
};

class playerCharacter {
public:
    int mag;
    int end;
    int mana;
    int addMana;
    int subMana;
    int health{ 0 };
    Injuries injuries{Injuries(5)};
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
        cout << "How much heals you get?\n";
        cin >> heal;
        this->health = this->health + heal;
        cout << "\n" << '\n';
    }

    void FaddMana() {
        cout << "Mana Gained?\n";
        cin >> addMana;
        this->mana = this->addMana + mana;
        cout << "Current Mana: ";
        cout << this->mana;
        cout << '\n' << '\n';
    }

    void subtractMana() {
        cout << "Mana Used?\n";
        cin >> subMana;
        this->mana = this->mana - subMana;
        cout << "Current Mana: ";
        cout << this->mana;
        cout << '\n' << '\n';
    }

};

int main() {

    string character_being_affected = "dsbahjbdjsh";
    map<string, playerCharacter> players;
    while (true) {
        cout << "Create a Character, yes or no?\n";
        cin >> input;
        if (input == "yes") {
            playerCharacter currentCharacter;
            currentCharacter.setName();
            currentCharacter.setHealth();
            currentCharacter.setMag();
            players[currentCharacter.name] = currentCharacter;
            }
        else {
            break;
        }
    }

    while (true)
    {
        string character_name;
        if (character_being_affected == "dsbahjbdjsh") {
            cout << "Which character is being affected?\n";
            cin >> character_name;
            character_being_affected = character_name;

        }
        cout << "Current Character: " << players[character_being_affected].name << '\n';
        cout << "Current Health: " << players[character_being_affected].health << '\n';
        cout << "Current Mana: " << players[character_being_affected].mana << '\n' << '\n';
        cout << "Max Minor Injuries: " << players[character_being_affected].injuries.maxMinor << '\n' << '\n';
        cout << "1. Take Damage" << '\n';
        cout << "2. Heal" << '\n';
        cout << "3. Add Mana" << '\n';
        cout << "4. Subtract Mana" << '\n';
        cout << "5. Check Injuries" << '\n';
        cout << "10. Change Player" << '\n' << '\n';
        cin >> choice;
        switch (choice) {
        case 1:
            players[character_being_affected].takeDamage();
            break;
        case 2:
            players[character_being_affected].Fheal();
            break;
        case 3:
            players[character_being_affected].FaddMana();
            break;
        case 4:
            players[character_being_affected].subtractMana();
            break;
        case 5:
            players[character_being_affected].injuries.getTotalInjuries();
        case 10:
            cin >> character_name;
            character_being_affected = character_name;
        }
    }
}