#include "Character.h"
#include <vector>
#include <stdint.h>
using namespace std;

#pragma once

class Team{
	public:
		Team();

		vector<Character*> teamMembers;
		
		void addMember(Character*);
		size_t teamSize;
};
