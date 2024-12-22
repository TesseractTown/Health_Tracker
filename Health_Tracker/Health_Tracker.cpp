#include <iostream>
using namespace std;

int damage;
int heal;
int choice;

class playerCharacter {
public:
	int mag;
	int health{ 0 };
	bool isDead{ false };

	int setHealth(int health) {
		cout << "What is your starting health?\n";
		cin >> health;
		this->health = health;
		return health;
	}

	int setMag(int Mag) {
		cout << "What is your Mag parameter?\n";
		cin >> mag;
		this->mag = mag;
		return mag;
	}

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
		cout << "Press 1 to take Damage" << '\n';
		cout << "Press 2 to Heal" << '\n';
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
