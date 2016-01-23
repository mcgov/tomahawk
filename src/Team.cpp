#include "Team.h"
#include "Character.h"
#include <vector>

Team::Team(){
	this->teamMembers = vector<Character*>();
	this->teamSize = 0;
}


		
void Team::addMember( Character* add ){
	this->teamMembers.push_back( add );
	this->teamSize++;
}
