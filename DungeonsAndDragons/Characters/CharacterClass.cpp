/*
 * CharacterClass.cpp
 *
 *  Created on: Jan 18, 2015
 *      Author: WillXiao
 */

#include <iostream>
#include "CharacterClass.h"

using namespace std;

CharacterClass::CharacterClass() {
	// TODO Auto-generated constructor stub

}

CharacterClass::~CharacterClass() {
	// TODO Auto-generated destructor stub
}

int CharacterClass::translateClass() {
	if(character_class == "Cleric")
		return 1;
	else if(character_class == "Fighter")
		return 2;
	else if(character_class == "Paladin")
		return 3;
	else if(character_class == "Ranger")
		return 4;
	else if(character_class == "Rogue")
		return 5;
	else if(character_class == "Warlock")
		return 6;
	else if(character_class == "Warlord")
		return 7;
	else if(character_class == "Wizard")
		return 8;
	else
		return -1;
}

