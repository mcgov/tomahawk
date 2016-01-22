#include "Team.h"

#pragma once

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

