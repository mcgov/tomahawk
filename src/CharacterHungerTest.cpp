#include "Character.h"
#include <iostream>
#include <cassert>
#include "Globals.h"
#include "TestTools.h"
using namespace std;

void testAttribute8( Character * testCharacter, uint8_t *attribute, Character::STATUS check_status, 
                        int set_to ,  bool desired_result, const char* status_msg  )
{
    //we should wrap these tests up into a function since we're copy and pasting so much.
    if (attribute != NULL){
        *attribute = set_to;         
        testCharacter->updateStatus();
    }
    cout <<  status_msg << ( testCharacter->characterStatus[check_status] ? "true" : "false" ) << '\n';
    assert ( testCharacter->characterStatus[check_status] == desired_result );
}

void testAttribute64( Character * testCharacter, int64_t *attribute, Character::STATUS check_status, 
                        int set_to ,  bool desired_result, const char* status_msg  )
{
    //we should wrap these tests up into a function since we're copy and pasting so much.
    /*
        Some attributes are 64 bit integers, and require different pointers.
        rather than cast, here's a different version.
    */
    if (attribute != NULL){
        *attribute = set_to;         
        testCharacter->updateStatus();
    }
    cout <<  status_msg << ( testCharacter->characterStatus[check_status] ? "true" : "false" ) << '\n';
    assert ( testCharacter->characterStatus[check_status] == desired_result );
}

int main(){

	Character test = Character("Jonny");

    /*Hunger tests*/
	test.addNewStatus(Character::HUNGRY);
	testAttribute8(&test, NULL , Character::HUNGRY, 0, true, "Hunger after forced set is: ");
    
    test.removeStatus(Character::HUNGRY);
	testAttribute8(&test, NULL , Character::HUNGRY, 0, false, "Hunger after force remove is: ");

    //set to above and below threshold test.
    testAttribute8( &test, &test.hunger, Character::HUNGRY, HUNGER_THRESHOLD + 1, true, "Hunger (above threshold) is : " );
    testAttribute8( &test, &test.hunger, Character::HUNGRY, HUNGER_THRESHOLD - 1, false, "Hunger (below threshold) is : " );
	
    testAttribute64( &test, &(test.current_hp), Character::DEAD, 1, false, "Character shouldn't be dead: death = " );   
    
    testAttribute64( &test, &(test.current_hp), Character::DEAD, 0, true, "Character should be dead: death = " );   
    
    testAttribute8( &test, &test.stamina, Character::TIRED, 100, false, "Character shouldn't be tired : tired= " );  
    testAttribute8( &test, &test.stamina, Character::TIRED, 0, true, "Character should be tired : tired= " );    
    
	cout << "All tests complete! :D huzzaah." <<'\n';

	return 1;
}