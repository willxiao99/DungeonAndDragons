/*
 * Player.h
 *
 *  Created on: Jan 18, 2015
 *      Author: WillXiao
 */

#ifndef PLAYER_H_
#define PLAYER_H_

#include <iostream>
#include "CharacterClass.h"
#include "Constants.h"
#include "Race.h"
using namespace std;

class Player: public CharacterClass, public Race {
	string name;
    
protected:
    int xp, gold; //Need to implement copper, silver etc. //need to implement levelling system
    int AC, fortitude, reflex, will; //defenses
    int level, max_hp, current_hp, base_initiative, initiative_misc_bonus; // basics
    int str, str_mod, con, con_mod, dex, dex_mod, intel, intel_mod, wis, wis_mod, cha, cha_mod; //ability scores
    int str_vs_con, dex_vs_intel, wis_vs_cha, light_armor_ac_bonus;
    int armor_proficiency, shield_proficiency;
    bool weapon_proficiencies[35], trained_skill[16];
    string equippedArmor, equipped_Shield;
    
public:
	Player();
	Player(string name, string race, string character_class);
    virtual ~Player();
    
    int getLevel();
    int levelUp();
    void equipArmor(string armor_name);
    void addTrainedSkill(int skill_ID);
    bool equippedArmorIsHeavy();
    virtual void DisplayPlayerInfo();
};

#endif /* PLAYER_H_ */
