#include "Character.h"
#include <iostream>
#include <cassert>
#include "Globals.h"
using namespace std;

int main(){

	Character test = Character("Jonny");
	cout <<  "Hunger is : " << ( test.characterStatus[Character::HUNGRY] ? "true" : "false" ) << '\n';
	assert (  test.characterStatus[Character::HUNGRY] == false ) ;

	test.addNewStatus(Character::HUNGRY);
	assert (  test.characterStatus[Character::HUNGRY] == true ) ;
	cout <<  "Hunger is : " << ( test.characterStatus[Character::HUNGRY] ? "true" : "false" ) << '\n';
	test.removeStatus(Character::HUNGRY);
	cout <<  "Hunger is : " << ( test.characterStatus[Character::HUNGRY] ? "true" : "false" ) << '\n';

	assert (  test.characterStatus[Character::HUNGRY] == false ) ;

	test.hunger = HUNGER_THRESHOLD + 1 ;
	test.updateStatus();
	assert ( test.characterStatus[Character::HUNGRY] == true ) ;
	cout <<  "Hunger is : " << ( test.characterStatus[Character::HUNGRY] ? "true" : "false" ) << '\n';

	test.hunger = HUNGER_THRESHOLD - 1 ;
	test.updateStatus();
	assert ( test.characterStatus[Character::HUNGRY] == false ) ;
	cout <<  "Hunger is : " << ( test.characterStatus[Character::HUNGRY] ? "true" : "false" ) << '\n';

    test.hitpoints = 1;
    test.updateStatus();
    assert ( test.characterStatus[Character::DEAD] == false) ;
    cout << "Character is dead : " << ( test.characterStatus[Character:: DEAD] ? "true" : "false" ) << '\n';
    
    test.hitpoints = 0;
    test.updateStatus();
    assert ( test.characterStatus[Character::DEAD] == true) ;
    cout << "Character is dead : " << ( test.characterStatus[Character:: DEAD] ? "true" : "false" ) << '\n';
    
    test.stamina = 1;
    test.updateStatus();
    assert ( test.characterStatus[Character::TIRED] == false) ;
    cout << "Character is tired : " << ( test.characterStatus[Character:: TIRED] ? "true" : "false" ) << '\n';
    
    test.stamina = 0;
    test.updateStatus();
    assert ( test.characterStatus[Character::TIRED] == true) ;
    cout << "Character is tired : " << ( test.characterStatus[Character:: TIRED] ? "true" : "false" ) << '\n';
    
	cout << "All tests complete! :D huzzaah." <<'\n';

	return 1;
}