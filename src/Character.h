
#pragma once

#include "Item.h"
#include <string>
#include <vector>
#include <stdint.h>
using namespace std;


class Character{


	//parent class for all characters

public:
	string name;
    
    
    enum STATUS { HEALTHY = 0, SICK, POISON, HUNGRY, THIRSTY, 
			  BLEEDING, NEED_POOP, NEED_PEE, DEAD, TIRED, LEN_STATUS }; //NOTE: don't move that last status plz thx.
	bool characterStatus[LEN_STATUS]; //now the boolean array can be addressed with the enum above.
	
	uint8_t hunger, thirst, bowels, bladder, level, stamina, max_stamina; 
    
	int64_t current_hp, current_mp , max_hp, max_mp;
    uint64_t money;
    
    
    
	Character(string);
	vector<Item> inventory;
	STATUS updateStatus();
	void addNewStatus(STATUS);
	void removeStatus(STATUS);





};

