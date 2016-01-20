
#ifndef CHARACTER
#define CHARACTER

#include "Item.h"
#include <string>
#include <vector>
using namespace std;


class Character{

	//parent class for all characters
public:
	string name;
	Character(string);
	vector<Item> inventory;

};

#endif