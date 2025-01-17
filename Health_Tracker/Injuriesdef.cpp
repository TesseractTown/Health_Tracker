#include <iostream>
#include "Injuries.h"
using namespace std;

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
    int inflictedInjuries{ 0 };

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

        int injuries_remaining = max(0, inflicted_injuries - num_injuries_can_inflict_this_tier);

        return injuries_remaining;
    }

    void removeInjuryOfTier(int removedInjuries, int& curr_num_injuries) {
        curr_num_injuries = max(0, curr_num_injuries - removedInjuries);
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