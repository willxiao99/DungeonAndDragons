/*
 * CharacterClass.cpp
 *
 *  Created on: Jan 18, 2015
 *      Author: HSIAOFamily
 */

#include <iostream>
#include "CharacterClass.h"

using namespace std;

CharacterClass::CharacterClass() {
	// TODO Auto-generated constructor stub

}

CharacterClass::CharacterClass(string character_class) {
	this->character_class = character_class;
	switch(TranslateClass()) {
		case 1:
			role = "Leader";
			role_description = ". You lead by shielding allies with your prayers, healing, and using powers that improve your allies’ attacks.";
			power_source = "Divine";
			power_source_description = ". You have been invested with the authority to wield divine power on behalf of a deity, faith, or philosophy.";
			//consider adding key abilities
            //armor ability
			//weapon_proficiency = {"Simple Melee", "Simple Ranged", "", "" ,"", "", "", "", "", "", "", "", "", "", "", "" ,"", "", "", ""};
			implement = "Holy Symbol";
			will_class_bonus = 2;
            //daily_surge_count = 7 + con_mod;
			break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            break;
        case 6:
            break;
        case 7:
            break;
        case 8:
            break;
		default:
            cout << "Error Creating Character: Invalid Class" << endl;
            break;
	}
}

CharacterClass::~CharacterClass() {
	// TODO Auto-generated destructor stub
}

int CharacterClass::TranslateClass() {
	if(character_class == "Cleric")
		return 1;
	if(character_class == "Fighter")
		return 2;
	if(character_class == "Paladin")
		return 3;
	if(character_class == "Ranger")
		return 4;
	if(character_class == "Rogue")
		return 5;
	if(character_class == "Warlock")
		return 6;
	if(character_class == "Warlord")
		return 7;
	if(character_class == "Wizard")
		return 8;
	else
		return -1;
}

