//
//  updateArray.cpp
//  Game2048
//
//  Created by MacOS on 3/25/17.
//  Copyright © 2017 MacOS. All rights reserved.
//

#include "updateArray.hpp"

void updateDown(int array[4][4], int& countEdit, int& score) {
    int j;
    countEdit = 0;
    for (j = 0; j < 4; j++) {
        countEdit += editArray(array[3][j], array[2][j], array[1][j], array[0][j], score);
    }
}

void updateUp(int array[4][4], int& countEdit, int& score) {
    int j;
    countEdit = 0;

    for (j = 0; j < 4; j++) {
        countEdit += editArray(array[0][j], array[1][j], array[2][j], array[3][j], score);
    }
}

void updateLeft(int array[4][4], int& countEdit, int& score) {
    int i;
    countEdit = 0;

    for (i = 0; i < 4; i++) {
        countEdit += editArray(array[i][0], array[i][1], array[i][2], array[i][3], score);
    }
}

void updateRight(int array[4][4], int& countEdit, int& score) {
    int i;
    countEdit = 0;

    for (i = 0; i < 4; i++) {
        countEdit += editArray(array[i][3], array[i][2], array[i][1], array[i][0], score);
    }
}

int editArray(int& a, int& b, int& c, int& d, int& score) {
    int arr[4];
    arr[0] = a;
    arr[1] = b;
    arr[2] = c;
    arr[3] = d;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (arr[j] == 0) {
                arr[j] = arr[j + 1];
                arr[j + 1] = 0;
            }
        }
    }
    if (arr[0] == arr[1]) {
        arr[0] *= 2;
        arr[1] = arr[2];
        arr[2] = arr[3];
        arr[3] = 0;
        score += arr[0];
    }
    if (arr[1] == arr[2]) {
        arr[1] *= 2;
        arr[2] = arr[3];
        arr[3] = 0;
        score += arr[1];
    }
    if (arr[2] == arr[3]) {
        arr[2] *= 2;
        arr[3] = 0;
        score += arr[2];
    }
    if (a == arr[0] && b == arr[1] && c == arr[2] && d == arr[3]) {
         return 1;
    }
    a = arr[0];
    b = arr[1];
    c = arr[2];
    d = arr[3];
    return 0;
}