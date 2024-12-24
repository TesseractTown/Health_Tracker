#include <iostream>
using namespace std;

int damage;
int heal;
int choice;

class playerCharacter {
public:
	int mag;
	int mana;
	int health{ 0 };
	bool isDead{ false };

	//Set PC Stats

	int setHealth(int health) {
		cout << "What is your starting health?\n";
		cin >> health;
		this->health = health;
		return health;
	}

	char setMag(char Mag, int mana) {
		cout << "What is your Mag parameter?\n";
		cin >> mag;
		this->mag = mag;
		switch (mag)
		{
		case '-':
			this->mana = 0;
			break;
		case 'E':
			this->mana = 20;
			break;
		case 'D':
			this->mana = 40;
			break;
		case 'C':
			this->mana = 60;
			break;
		case 'B':
			this->mana = 80;
			break;
		case 'A':
			this->mana = 100;
			break;
		case "A+1":
			this->mana = 120;
			break;
		case "A+2":
			this->mana = 140;
			break;
		case "A+3":
			this->mana = 160;
			break;
		case "A+4":
			this->mana = 180;
			break;
		case "A+5":
			this->mana = 200;
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
		cout << "Current Health: ";
		cout << this->health;
		cout << "\n" << '\n';
	}

	void Fheal() {
		cout << "How much heals you get?\n";
		cin >> heal;
		this->health = this->health + heal;
		cout << "Current Health: ";
		cout << this->health;
		cout << "\n" << '\n';
	}


};

int main() {
	playerCharacter myPC;

	static bool initialized;
	if (!initialized) {
		initialized = false;
		myPC.setHealth(myPC.health);
		myPC.setMag(myPC.mag);
		initialized = true;
	}

	while (true)
	{
		cout << "1. Take Damage" << '\n';
		cout << "2. Heal" << '\n';
		cout << "3. Add Mana" << '\n';
		cout << "4. Subtract Mana" << '\n';
		cin >> choice;
		switch (choice) {
		case 1:
			myPC.takeDamage();
			break;
		case 2:
			myPC.Fheal();
			break;
		}
	}
}
