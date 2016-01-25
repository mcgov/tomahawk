#include <string>
#include "Character.h"
#include "Item.h"
#include "Globals.h"

using namespace std;



Character::Character(string name){
    //defining character properties
	this->hunger = 0;
	this->thirst = 0;
	this->bladder = 0;
	this->bowels = 0;
    this->current_hp = 0; //  <-- we should have some function to set these based on level and stats
    this->current_mp = 0; // <--- this one too
    this->max_hp = 0;  //also these I guess.
    this->max_mp = 0;  //and dis
    this->stamina = 0;
    
    //setting character status enums to their defaults
	for ( int i = 0; i < Character::LEN_STATUS; i++ ){
		this->characterStatus[i] = false;
	}
    
	this->name = name;
	this->inventory = vector<Item>();

}

void Character::addNewStatus( Character::STATUS newStatus ){
	this->characterStatus[newStatus] = true;
}

void Character::removeStatus( Character::STATUS newStatus ){
	this->characterStatus[newStatus] = false;
}

Character::STATUS Character::updateStatus( ){
	/*hunger*/
	if ( this->hunger >= HUNGER_THRESHOLD )
		this->addNewStatus( Character::HUNGRY );

	if (this->hunger < HUNGER_THRESHOLD )
		this->removeStatus( Character::HUNGRY );

	/*thirst*/
	if ( this->thirst >= THIRST_THRESHOLD )
		this->addNewStatus( Character::THIRSTY );

	if (this->thirst < THIRST_THRESHOLD )
		this->removeStatus( Character::THIRSTY );

	/*bathroom*/
	if ( this->bowels >= POO_THRESHOLD )
		this->addNewStatus( Character::NEED_POOP );
	if ( this->bladder >= PEE_THRESHOLD )
		this->addNewStatus( Character::NEED_PEE );
	
	if ( this->bowels < POO_THRESHOLD )
		this->removeStatus( Character::NEED_POOP );
	if ( this->bladder < PEE_THRESHOLD )
		this->removeStatus( Character::NEED_PEE );
        
    /* Health */
	if ( this->current_hp <= 0 )
		this->addNewStatus( Character::DEAD );
    else if ( this->current_hp > 0 )
		this->removeStatus( Character::DEAD );

	if (this->stamina > 0 )
		this->removeStatus( Character::TIRED );
    else if (this->stamina <= 0 )
		this->addNewStatus( Character::TIRED );

}

