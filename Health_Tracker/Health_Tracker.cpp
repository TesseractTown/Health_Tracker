#include <iostream>
#include <map>
#include <vector>
#include <string>
#include "Injuries.h"
#include "PlayerChar.h"
using namespace std;

int damage;
int heal;
int choice;
string input;



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
        cout << "8. Change Player" << '\n' << '\n';
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
        case 8:
            cin >> character_name;
            character_being_affected = character_name;
        }
    }
}