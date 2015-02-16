/*
 * Player.h
 *
 *  Created on: Jan 18, 2015
 *      Author: HSIAOFamily
 */

#ifndef PLAYER_H_
#define PLAYER_H_

#include <iostream>
#include "CharacterClass.h"
#include "Race.h"
using namespace std;

class Player: public CharacterClass, public Race { //Check whether inheriting multiple classes can work like this.
	string name, race;
	int xp, gold;
    int AC, fortitude, reflex, will; //defenses
    
protected:
    int level, max_hp, current_hp, initiative, initiative_misc_bonus; // basics
    int str, str_mod, con, con_mod, dex, dex_mod, intel, intel_mod, wis, wis_mod, cha, cha_mod; //ability scores
    int armor_proficiency, shield_proficiency;
    bool club_proficiency;
    bool dagger_proficiency;
    bool javelin_proficiency;
    bool mace_proficiency;
    //etc.

public:
	Player();
	Player(string name, string race, string character_class);
    virtual ~Player();
    
    int getLevel();
    int levelUp();
    virtual void DisplayPlayerInfo();
};

#endif /* PLAYER_H_ */
