//
//  logic.cpp
//  2048_game
//
//  Created by MacOS on 4/16/17.
//  Copyright © 2017 MacOS. All rights reserved.
//

#include "logic.hpp"
#include <cstdlib>

void createRandNum(int array[4][4]) {
    int i, j;
    if (checkFullArrray(array) == false) {
        do {
            i = rand() % 4;
            j = rand() % 4;
        } while (array[i][j] != 0);
        array[i][j] = randomNumber();
    }
}

int gameNotOver(int array[4][4]) {
    int i, j;
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            if (array[i][j] == 0) {
                return 1;
            }
            if ((array[i][j] == array[i+1][j] && i < 3) || (array[i][j] == array[i][j+1] && j < 3)) {
                return 1;
            }
        }
    }
    return 0;
}

bool checkFullArrray(int array[4][4]) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (array[i][j] == 0) {
                return false;
            }
        }
    }
    return true;
}

int randomNumber() {
    if ((rand() % 100) > 40) {
        return 2;
    }
    return 4;
}
