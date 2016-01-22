#include <string>
#include "Character.h"
#include "Item.h"
#include "Globals.h"

using namespace std;



Character::Character(string name){

	this->hunger = 0x00;
	this->thirst = 0x00;
	this->bladder = 0x00;
	this->bowels = 0x00;
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

	if (this->THIRSTY < THIRST_THRESHOLD )
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


	/*bladder*/



}

