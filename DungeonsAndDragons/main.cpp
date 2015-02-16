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

int main() {
    Player WillXiao("WillXiao", "Dragonborn", "Cleric");
    WillXiao.DisplayPlayerInfo();
    
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
