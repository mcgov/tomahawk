
#pragma once

#include "Item.h"
#include <string>
#include <vector>
using namespace std;


class Character{


	//parent class for all characters

public:
	enum STATUS { HEALTHY = 0, SICK, POISON, HUNGRY, THIRSTY, 
			  BLEEDING, NEED_POOP, NEED_PEE, DEAD, LEN_STATUS }; //NOTE: don't move that last status plz thx.
	bool characterStatus[LEN_STATUS];
	uint8_t hunger, thirst, bowels, bladder;
	
	string name;
	Character(string);
	vector<Item> inventory;
	STATUS updateStatus();
	void addNewStatus(STATUS);
	void removeStatus(STATUS);





};

