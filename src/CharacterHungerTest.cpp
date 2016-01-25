#include "Character.h"
#include <iostream>
#include <cassert>
#include "Globals.h"
using namespace std;

void testAttribute( Character * testCharacter, uint8_t *attribute, Character::STATUS check_status, 
                        int set_to ,  bool desired_result, const char* status_msg  )
{
    //we should wrap these tests up into a function since we're copy and pasting so much.
    if (attribute != NULL){
        *attribute = set_to;         
    }
    testCharacter->updateStatus();
    cout <<  status_msg << ( testCharacter->characterStatus[check_status] ? "true" : "false" ) << '\n';
    assert ( testCharacter->characterStatus[check_status] == desired_result );
}

int main(){

	Character test = Character("Jonny");

    /*Hunger tests*/
	test.addNewStatus(Character::HUNGRY);
	testAttribute(&test, NULL , Character::HUNGRY, 0, true, "Hunger after forced set is: ");
    
    test.removeStatus(Character::HUNGRY);
	testAttribute(&test, NULL , Character::HUNGRY, 0, false, "Hunger after force remove is: ");

    //set to above and below threshold test.
    testAttribute( &test, &test.hunger, Character::HUNGRY, HUNGER_THRESHOLD + 1, true, "Hunger (above threshold) is : " );
    testAttribute( &test, &test.hunger, Character::HUNGRY, HUNGER_THRESHOLD - 1, false, "Hunger (below threshold) is : " );
	
    test.current_hp = 1;
    test.updateStatus();
    assert ( test.characterStatus[Character::DEAD] == false) ;
    cout << "Character is dead : " << ( test.characterStatus[Character:: DEAD] ? "true" : "false" ) << '\n';
    
    test.current_hp = 0;
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