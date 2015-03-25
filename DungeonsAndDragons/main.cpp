//
//  main.cpp
//  DungeonsAndDragons
//
//  Created by William Hsiao on 2/16/15.
//  Copyright (c) 2015 William Hsiao. All rights reserved.
//

//search up <fstream> in cpp primer

#include <iostream>
#include "Characters/Player.h"
#include "Characters/Race.h"
#include "Characters/CharacterClass.h"
using namespace std;

int rollDie(int number, int sides) {
    int x = 0;
    for(int i=0; i<number; i++) {
        x += rand() % sides;
    }
    return x;
}

void createPlayerCharacter() {
    string name_input, race_choice, class_choice;
    cout << "What's your name? ";
    cin >> name_input;
    cout << endl << "Pick a race: ";
    cin >> race_choice;
    cout << endl << "Pick a class: ";
    cin >> class_choice;
    cout << endl;
    Player WillXiao(name_input, race_choice, class_choice);
    WillXiao.DisplayPlayerInfo();
}

int main() {
    createPlayerCharacter();
    
    for(int i = 0; i < 10; i++) {
        int temp = rollDie(3, 4);
        if(!i) {
            cout << temp;
        }
        else {
            cout << " " << temp;
        }
    }
    return 0;
}
