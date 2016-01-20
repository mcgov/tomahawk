#include "Character.h"
#include <vector>
#include <stdint.h>
using namespace std;

#ifndef TEAM
#define TEAM

class Team{
	public:
		vector<Character*> teamMembers;
		size_t teamSize;
};

#endif