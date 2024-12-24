#pragma once
class Injuries {
public:
	int maxMinor;
	int maxModerate;
	int maxSevere;
	int currMinor{ 0 };
	int currModerate{ 0 };
	int currSevere{ 0 };
	int currCritical{ 0 };

	Injuries(int end);

	void setInjuries(int end);
	int getTotalInjuries() {};
	int getInjuryPenalty() {};
};