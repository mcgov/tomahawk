#include "Battle.h"
#include "Team.h"
#include "Character.h"
#include <iostream>
#include <vector>
using namespace std;

int main(){

	int TEAM_SIZE = 5;
	Character* char0[TEAM_SIZE];
	Character* char1[TEAM_SIZE];
	Team team0 = Team();
	Team team1 = Team();
	for (int i = 0; i < TEAM_SIZE; i++){
		size_t bufsize = 10;
		char buffer[bufsize];
		snprintf(buffer, bufsize, "%d", i);
		cout << buffer << '\n';
		char0[i] = new Character( "Character " + string( buffer ) );
		snprintf(buffer, bufsize, "%d", TEAM_SIZE + i);
		cout << buffer << '\n';
		char1[i] = new Character( "Character " +  string( buffer ) );
	}

	for ( Character* ch : char0 )
		team0.addMember(ch);
	for ( Character* ch : char1 )
		team1.addMember(ch);
	
	//mattypants

	vector<Team*> teams = vector<Team*>();
	teams.push_back(&team0);
	teams.push_back(&team1);

	Battle test_battle = Battle(teams);

	for ( Character* ch : char0 )
		delete ch;
	for ( Character* ch : char1 )
		delete ch;

}