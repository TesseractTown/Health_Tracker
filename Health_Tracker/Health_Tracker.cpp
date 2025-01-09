#include <iostream>
#include <map>
#include <vector>
using namespace std;


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
    int maxCritical;
    int currMinor{ 0 };
    int currModerate{ 0 };
    int currSevere{ 0 };
    int currCritical{ 0 };
    int inflictedInjuries{0};

    //constructor

    Injuries(int end) {
        setInjuries(end);
    }

    //functions

    void getTotalInjuries() {
        cout << "----------------------" << '\n';
        cout << "Minor: " << currMinor << "|" << maxMinor << '\n';
        cout << "Moderate: " << currModerate << "|" << maxModerate << '\n';
        cout << "Severe: " << currSevere << "|" << maxSevere << '\n';
        cout << "Critical: " << currCritical << '\n' << '\n';
    }

    int getInjuryPenalty() {};

  
    void addInjury() {
        cout << "----------------------" << '\n';
        cout << "How many injuries do you take?\n";
        cin >> inflictedInjuries;
        int injuries_remaining = inflictInjuryOfTier(inflictedInjuries, maxMinor, currMinor);

        injuries_remaining = inflictInjuryOfTier(injuries_remaining, maxModerate, currModerate);

        injuries_remaining = inflictInjuryOfTier(injuries_remaining, maxSevere, currSevere);

        currCritical = injuries_remaining;
    };

    int inflictInjuryOfTier(int inflicted_injuries, int max_injuries, int& curr_num_injuries) {
        int injuries_remaining_for_max = max_injuries - curr_num_injuries; // positive

        int num_injuries_can_inflict_this_tier = min(injuries_remaining_for_max, inflicted_injuries);

        curr_num_injuries = min(max_injuries, num_injuries_can_inflict_this_tier + curr_num_injuries);

        int injuries_remaining = max(0, inflicted_injuries  - num_injuries_can_inflict_this_tier);

        return injuries_remaining;
    }

    void removeInjuryOfTier(int removedInjuries, int& curr_num_injuries){
         curr_num_injuries =  max( 0, curr_num_injuries - removedInjuries);
    }

    void removeInjury() {
        int injurySeverity;
        int removedInjuries;

        cout << "What tier of Injury?" << '\n';
        cin >> injurySeverity;
        cout << "How Many Injuries?" << 'n';
        cin >> removedInjuries;
        switch (injurySeverity) {
            case 1:
                removeInjuryOfTier(removedInjuries, currMinor);
                break;
            case 2:
                removeInjuryOfTier(removedInjuries, currModerate);
                break;
            case 3:
                removeInjuryOfTier(removedInjuries, currSevere);
                break;
            case 4:
                removeInjuryOfTier(removedInjuries, currCritical);
                break;
        }
    }



    void setInjuries(int end) {
        switch (end) {
        case 0:
            maxMinor = 1;
            maxModerate = 1;
            maxSevere = 0;
            maxCritical = 0;
            break;
        case 1:
            maxMinor = 1;
            maxModerate = 1;
            maxSevere = 1;
            maxCritical = 2;
            break;
        case 2:
            maxMinor = 2;
            maxModerate = 1;
            maxSevere = 1;
            maxCritical = 2;
            break;
        case 3:
            maxMinor = 3;
            maxModerate = 2;
            maxSevere = 1;
            maxCritical = 2;
            break;
        case 4:
            maxMinor = 4;
            maxModerate = 2;
            maxSevere = 1;
            maxCritical = 2;
            break;
        case 5:
            maxMinor = 5;
            maxModerate = 3;
            maxSevere = 2;
            maxCritical = 2;
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
    PlayerThp playerthp;
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

class THP {

public:

    string tempHpName;
    int tempHpValue;
    int tempHpMax;

    THP(string tempHpName, int tempHpValue, int tempHPMax) {
        tempHpName = tempHpName;
        tempHpValue = tempHpValue;
        tempHpMax = tempHpMax;
    }

    void addTempHp() {
        int tempHpAdded;

        cout << "How much Temp HP do you add?" << '\n';
            cin >> tempHpAdded;

        tempHpValue = min(tempHpMax, tempHpAdded + tempHpValue);
    }

    void subtractTempHp() {
        int tempHpSubtracted;
        
        cout << "Subract how much Temp HP?" << '\n';
        cin >> tempHpSubtracted;
        tempHpValue = max(0, tempHpValue - tempHpSubtracted);
    }
};


class PlayerThp {
    // kill me

public:

    vector<string> temphpNames;
    map<string, THP> ActiveTempHps;

    void createTempHPObject() {
        string tempHpName;
        int tempHpValue;
        int tempHpMax;

        cout << "What is the Temp HP objects Name?";
        cin >> tempHpName;
        temphpNames.push_back(tempHpName);

        cout << "Max Value?";
        cin >> tempHpValue;
        tempHpMax = tempHpValue;

        THP thp = THP(tempHpName, tempHpValue, tempHpMax); //encapsulates the behaviour/abstarts behaviour

        ActiveTempHps[tempHpName] = thp;

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
        cout << "----------------------" << '\n';
        cout << "Current Character: " << players[character_being_affected].name << '\n';
        cout << "Current Health: " << players[character_being_affected].health << '\n';
        cout << "Current Mana: " << players[character_being_affected].mana << '\n' << '\n';
        cout << "1. Take Damage" << '\n';
        cout << "2. Heal" << '\n';
        cout << "3. Add Mana" << '\n';
        cout << "4. Subtract Mana" << '\n';
        cout << "5. Check Injuries" << '\n';
        cout << "6. Add Injury" << '\n';
        cout << "7. Remove Injury" << '\n';
        cout << "8. Add Temp HP";
        cout << "9. Subtract Temp HP";
        cout << "10. Check Temp HP";
        cout << "99. Change Player" << '\n' << '\n';
        cout << "----------------------" << '\n';
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
            break;
        case 6: 
            players[character_being_affected].injuries.addInjury();
            break;
        case 7:
            players[character_being_affected].injuries.removeInjury();
            break;
        case 8:
            players[character_being_affected].playerthp.addTempHp();
            break;
        case 9:
            players[character_being_affected].playerthp.subtractTempHp();
            break;
        case 10:
            //yada yada
        case 99:
            cin >> character_name;
            character_being_affected = character_name;
        }
    }
}