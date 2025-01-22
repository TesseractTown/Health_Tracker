#pragma once

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

    Injuries(int end);
    void getTotalInjuries();
    int getInjuryPenalty();
    void addInjury();
    int inflictInjuryOfTier(int inflicted_injuries, int max_injuries, int& curr_num_injuries);
    void removeInjuryOfTier(int removedInjuries, int& curr_num_injuries);
    void removeInjury();
    void setInjuries(int end);

};

