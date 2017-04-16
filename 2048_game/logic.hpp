//
//  logic.hpp
//  2048_game
//
//  Created by MacOS on 4/16/17.
//  Copyright © 2017 MacOS. All rights reserved.
//

#ifndef logic_hpp
#define logic_hpp

void createRandNum(int array[4][4]); // create a random number in array
int gameNotOver(int array[4][4]);
bool checkFullArrray(int array[4][4]);
int randomNumber();
int checkWinGame(int array[4][4]);

#endif /* logic_hpp */
