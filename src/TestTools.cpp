#include "TestTools.h"
#include <cassert>
#include <iostream>

using namespace std;

static void testAttribute8( Character * testCharacter, uint8_t *attribute, Character::STATUS check_status, 
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

static void testAttribute64( Character * testCharacter, int64_t *attribute, Character::STATUS check_status, 
                        int set_to ,  bool desired_result, const char* status_msg  )
{
    /*
        Some attributes are 64 bit integers, and require different pointers.
        so rather than cast, here's a different version! Don't repeat yourself. *ctrl c* *ctrl v* *ctrl v*
    */
    
    if (attribute != NULL){
        *attribute = set_to;         
        testCharacter->updateStatus();
    }
    cout <<  status_msg << ( testCharacter->characterStatus[check_status] ? "true" : "false" ) << '\n';
    assert ( testCharacter->characterStatus[check_status] == desired_result );
}