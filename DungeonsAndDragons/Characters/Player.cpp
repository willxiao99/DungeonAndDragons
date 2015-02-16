/*
 * Player.cpp
 *
 *  Created on: Jan 18, 2015
 *      Author: WillXiao
 */

#include <iostream>
#include "Player.h"
using namespace std;

Player::Player() {
	// TODO Auto-generated constructor stub
}

Player::Player(string name, string race, string character_class) {
	//player attributes
	this->name = name;
    this->race = race;
    this->character_class = character_class;
    
	level = 1;
	gold = 100;
	xp = 0;
    
    base_initiative = dex_mod + level/2 + initiative_misc_bonus;
    
    str = 16; str_mod = str/2-5;
    con = 15; con_mod = con/2-5;
    dex = 14; dex_mod = dex/2-5;
    intel = 13; intel_mod = intel/2-5;
    wis = 11; wis_mod = wis/2-5;
    cha = 11; cha_mod = cha/2-5;
    
    AC = 10 + level/2; //Ommitted: total_armor_ac, light_abil_ac_bonus, enhancement_ac_bonus, total_feat_bonus_ac
    fortitude = 10 + level/2;
    reflex = 10 + level/2;
    will = 10 + level/2;

	//race attributes

	//class attributes
    switch(TranslateClass()) {
        case 1:
            role = "Leader";
            role_description = ". You lead by shielding allies with your prayers, healing, and using powers that improve your allies’ attacks.";
            power_source = "Divine";
            power_source_description = ". You have been invested with the authority to wield divine power on behalf of a deity, faith, or philosophy.";
            //consider adding key abilities
            armor_proficiency = 4;
            //weapon_proficiency = {"Simple Melee", "Simple Ranged", "", "" ,"", "", "", "", "", "", "", "", "", "", "", "" ,"", "", "", ""};
            implement = "Holy Symbol";
            will_class_bonus = 2;
            
            base_health = 12;
            max_hp = base_health + con + 5*(level-1);
            current_hp = max_hp;
            daily_surge_count = 7 + con_mod;
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            break;
        default:
            cout << "Error Creating Character: Invalid Class" << endl;
            break;
    }
}

void Player::DisplayPlayerInfo() {
    cout << "Name: " << name << endl;
    cout << "Level: " << level << endl;
    cout << "Health: " << current_hp << "/" << max_hp << endl;
    cout << endl;
    cout << "Initiative: " << base_initiative + initiative_misc_bonus << endl;
    cout << endl;
    cout << "Defenses" << endl;
    cout << "AC: " << AC << endl;
    cout << "Fortitude: " << fortitude << endl;
    cout << "Reflex: " << reflex << endl;
    cout << "Will: " << will << endl;
}

Player::~Player() {
	// TODO Auto-generated destructor stub
}
