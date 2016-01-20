#include "Team.h"

#ifndef BATTLE
#define BATTLE

#define MAX_TEAMS 2

class Battle{

public:
	Team* teams[MAX_TEAMS];
	int n_teams;
	int whichTeam;
	vector<int> currentCharacterIndex;
	Battle( vector<Team*> );
	void getNextMove();


};

#endif