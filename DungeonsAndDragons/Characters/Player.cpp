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
    
    str = 16; str_mod = (str/2)-5;
    con = 15; con_mod = (con/2)-5;
    dex = 14; dex_mod = (dex/2)-5;
    intel = 13; intel_mod = (intel/2)-5;
    wis = 11; wis_mod = (wis/2)-5;
    cha = 11; cha_mod = (cha/2)-5;
    
    initiative_misc_bonus = 0;
    base_initiative = dex_mod + (level/2) + initiative_misc_bonus;

    str_vs_con = str_mod > con_mod ? str_mod:con_mod;
    dex_vs_intel = dex_mod > intel_mod ? dex_mod:intel_mod;
    wis_vs_cha = wis_mod > cha_mod ? wis_mod:cha_mod;
    
    equippedArmor = "Cloth Armor";
    
    if(!equippedArmorIsHeavy())
        light_armor_ac_bonus = 0;
    else
        light_armor_ac_bonus = dex_vs_intel;
    
    
    AC = 10 + level/2 + light_armor_ac_bonus; //Ommitted: total_armor_ac, enhancement_ac_bonus, total_feat_bonus_ac
    fortitude = 10 + level/2 + str_vs_con;
    reflex = 10 + level/2 + dex_vs_intel;
    will = 10 + level/2 + wis_vs_cha;
    for(int i = 0; i <= sizeof(weapon_proficiencies); i++)
        weapon_proficiencies[i] = false;

	//race attributes

	//class attributes, still need to implement class features, powers, deities, and paragon paths.
    switch(translateClass()) {
        case 1:
            role = "Leader";
            role_description = ". You lead by shielding allies with your prayers, healing, and using powers that improve your allies’ attacks.";
            power_source = "Divine";
            power_source_description = ". You have been invested with the authority to wield divine power on behalf of a deity, faith, or philosophy.";
            //key_abilities = "Wisdom, Strength, Charisma"
            armor_proficiency = 4;
            shield_proficiency = 0;
            weapon_proficiencies[club] = true;
            weapon_proficiencies[dagger] = true;
            weapon_proficiencies[javelin] = true;
            weapon_proficiencies[mace] = true;
            weapon_proficiencies[sickle] = true;
            weapon_proficiencies[spear] = true;
            weapon_proficiencies[greatclub] = true;
            weapon_proficiencies[morningstar] = true;
            weapon_proficiencies[quarterstaff] = true;
            weapon_proficiencies[scythe] = true;
            weapon_proficiencies[hand_crossbow] = true;
            weapon_proficiencies[sling] = true;
            weapon_proficiencies[crossbow] = true;
            implement = "Holy Symbol";
            fort_class_bonus = 0;
            ref_class_bonus = 0;
            will_class_bonus = 2;
            base_health = 12;
            hp_level_growth = 5;
            base_surge_count = 7;
            trained_skill[religion] = true;
            {string class_skill_choice;
            cout << "Choose one skill to train out of Arcana (Int), Diplomacy (Cha), Heal (Wis), History (Int), Insight (Wis), Religion (Int): ";
            cin >> class_skill_choice;
            cout << endl;
            if(class_skill_choice == "Arcana")
                trained_skill[arcana] = true;
            else if(class_skill_choice == "Diplomacy")
                trained_skill[diplomacy] = true;
            else if(class_skill_choice == "Heal")
                trained_skill[heal] = true;
            else if(class_skill_choice == "History")
                trained_skill[history] = true;
            else if(class_skill_choice == "Insight")
                trained_skill[insight] = true;
            else if(class_skill_choice == "Religion")
                trained_skill[religion] = true;
            else
                cout << "Invalid skill choice. Sucks to be you, cus you don't get to pick again." << endl;
            }
            break;
        case 2:
            role = "Defender";
            role_description = ". You are very tough and have the exceptional ability to contain enemies in melee.";
            power_source = "Martial";
            power_source_description = ". You have become a master of combat through endless hours of practice, determination, and your own sheer physical toughness.";
            //key_abilities = "Strength, Dexterity, Wisdom, Constitution"
            armor_proficiency = 5;
            shield_proficiency = 2;
            weapon_proficiencies[club] = true;
            weapon_proficiencies[dagger] = true;
            weapon_proficiencies[javelin] = true;
            weapon_proficiencies[mace] = true;
            weapon_proficiencies[sickle] = true;
            weapon_proficiencies[spear] = true;
            weapon_proficiencies[greatclub] = true;
            weapon_proficiencies[morningstar] = true;
            weapon_proficiencies[quarterstaff] = true;
            weapon_proficiencies[scythe] = true;
            weapon_proficiencies[battleaxe] = true;
            weapon_proficiencies[flail] = true;
            weapon_proficiencies[handaxe] = true;
            weapon_proficiencies[longsword] = true;
            weapon_proficiencies[scimitar] = true;
            weapon_proficiencies[short_sword] = true;
            weapon_proficiencies[throwing_hammer] = true;
            weapon_proficiencies[warhammer] = true;
            weapon_proficiencies[war_pick] = true;
            weapon_proficiencies[falchion] = true;
            weapon_proficiencies[glaive] = true;
            weapon_proficiencies[greataxe] = true;
            weapon_proficiencies[greatsword] = true;
            weapon_proficiencies[halberd] = true;
            weapon_proficiencies[heavy_flail] = true;
            weapon_proficiencies[longspear] = true;
            weapon_proficiencies[maul] = true;
            weapon_proficiencies[hand_crossbow] = true;
            weapon_proficiencies[sling] = true;
            weapon_proficiencies[crossbow] = true;
            weapon_proficiencies[longbow] = true;
            weapon_proficiencies[shortbow] = true;
            implement = "";
            fort_class_bonus = 2;
            ref_class_bonus = 0;
            will_class_bonus = 0;
            base_health = 15;
            hp_level_growth = 6;
            base_surge_count = 9;
            trained_skill[religion] = true;
            {string class_skill_choice;
            cout << "Choose one skill to train out of Arcana (Int), Diplomacy (Cha), Heal (Wis), History (Int), Insight (Wis), Religion (Int): ";
            cin >> class_skill_choice;
            cout << endl;
            if(class_skill_choice == "Arcana")
                trained_skill[arcana] = true;
            else if(class_skill_choice == "Diplomacy")
                trained_skill[diplomacy] = true;
            else if(class_skill_choice == "Heal")
                trained_skill[heal] = true;
            else if(class_skill_choice == "History")
                trained_skill[history] = true;
            else if(class_skill_choice == "Insight")
                trained_skill[insight] = true;
            else if(class_skill_choice == "Religion")
                trained_skill[religion] = true;
            else
                cout << "Invalid skill choice. Sucks to be you, cus you don't get to pick again." << endl;
            }
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
    max_hp = base_health + con + hp_level_growth*(level-1);
    current_hp = max_hp;
    base_surge_count = 9 + con_mod;
}

Player::~Player() {
	// TODO Auto-generated destructor stub
}


void Player::DisplayPlayerInfo() {
    cout << "Name: " << name << endl;
    cout << "Level: " << level << endl;
    cout << "Health: " << current_hp << "/" << max_hp << endl;
    cout << endl;
    cout << "Base Initiative: " << base_initiative << endl;
    cout << endl;
    cout << "Defenses" << endl;
    cout << "AC: " << AC << endl;
    cout << "Fortitude: " << fortitude << endl;
    cout << "Reflex: " << reflex << endl;
    cout << "Will: " << will << endl;
}

void Player::equipArmor(string armor_name) {
    equippedArmor = armor_name;
}

bool Player::equippedArmorIsHeavy() {
    return false;
}

void Player::addTrainedSkill() {
    bool x = true;
    string skill_name;
    int skill_ID;
    while(x) {
        cin >> skill_name;
        skill_ID = translateSkill(skill_name);
        cout << endl;
        if(trained_skill[skill_ID] == false) {
            trained_skill[skill_ID] = true;
            x = false;
        }
        else if(trained_skill[skill_ID] == true)
            cout << "Skill is already trained, pick another skill." << endl;
        else
            cout << "Skill does not exist, try again." << endl;
    }
}

void Player::addTrainedSkill(int skill_ID) {
    
}

int Player::translateSkill(string skill_name) {
    if(skill_name == "Acrobatics")
        return 0;
    else if(skill_name == "Arcana")
        return 1;
    else if(skill_name == "Athletics")
        return 2;
    else if(skill_name == "Bluff")
        return 3;
    else if(skill_name == "Diplomacy")
        return 4;
    else if(skill_name == "Dungeoneering")
        return 5;
    else if(skill_name == "Endurance")
        return 6;
    else if(skill_name == "Heal")
        return 7;
    else if(skill_name == "History")
        return 8;
    else if(skill_name == "Insight")
        return 9;
    else if(skill_name == "Intimidate")
        return 10;
    else if(skill_name == "Nature")
        return 11;
    else if(skill_name == "Perception")
        return 12;
    else if(skill_name == "Religion")
        return 13;
    else if(skill_name == "Stealth")
        return 14;
    else if(skill_name == "Streetwise")
        return 15;
    else if(skill_name == "Thievery")
        return 16;
    else
        return -1;
}
