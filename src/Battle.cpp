#include "Team.h"
#include "Battle.h"
#include <cstdlib>
#include <iostream>
#include <cassert>
using namespace std;

Battle::Battle( vector<Team*> teams){
	n_teams = teams.size();
	assert( n_teams >= 1 );

	for ( int i = 0; i < n_teams ; i++ ){
		this->teams[i] = teams.at(i);
		this->currentCharacterIndex.push_back(0);
	}
	whichTeam = rand() % n_teams;
}

void Battle::getNextMove()
{
	if ( teams[whichTeam]->teamSize == currentCharacterIndex.at(whichTeam) ){ //if we have reached the end of this vector...
		currentCharacterIndex.at(whichTeam) = 0 ;	//reset it
	}
	Character* currentChar = teams[whichTeam]->teamMembers.at( currentCharacterIndex.at(whichTeam) ); //mouthfull, grab the next character to make a move
	
	cout << "Next character was " << currentChar->name << '\n';
	//do some stuff

	currentCharacterIndex.at(whichTeam) += 1 ; 
	whichTeam = (whichTeam+1)%n_teams;

}