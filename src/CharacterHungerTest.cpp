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
	cout <<  "Hunger is : " << ( test.characterStatus[Character::HUNGRY] ? "true" : "false" ) << '\n';
	assert (  test.characterStatus[Character::HUNGRY] == false ) ;

	test.addNewStatus(Character::HUNGRY);
	assert (  test.characterStatus[Character::HUNGRY] == true ) ;
	cout <<  "Hunger is : " << ( test.characterStatus[Character::HUNGRY] ? "true" : "false" ) << '\n';
	
    test.removeStatus(Character::HUNGRY);
	cout <<  "Hunger is : " << ( test.characterStatus[Character::HUNGRY] ? "true" : "false" ) << '\n';
	assert (  test.characterStatus[Character::HUNGRY] == false ) ;

    testAttribute( &test, &test.hunger, Character::HUNGRY, HUNGER_THRESHOLD + 1, true, "Hunger is : " );
        testAttribute( &test, &test.hunger, Character::HUNGRY, HUNGER_THRESHOLD - 1, false, "Hunger is : " );
    //i don't know if this is more or less clear... humm.
    
    /* 
	test.updateStatus();
	assert ( test.characterStatus[Character::HUNGRY] == true ) ;
	cout <<  "Hunger is : " << ( test.characterStatus[Character::HUNGRY] ? "true" : "false" ) << '\n';
    */
	
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