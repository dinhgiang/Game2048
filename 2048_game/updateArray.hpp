//
//  updateArray.hpp
//  Game2048
//
//  Created by MacOS on 3/25/17.
//  Copyright © 2017 MacOS. All rights reserved.
//

#ifndef updateArray_hpp
#define updateArray_hpp

void createRandNum(int array[4][4]); // create a random number in array
void updateDown(int array[4][4], int& countEditm, int& score);
void updateUp(int array[4][4], int& countEdi, int& score);
void updateLeft(int array[4][4], int& countEdit, int& score);
void updateRight(int array[4][4], int& countEdit, int& score);
int editArray(int& a, int& b, int& c, int& d, int& score); // plus number in column/row

#endif /* updateArray_hpp */