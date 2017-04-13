//
//  main.cpp
//  Game2048
//
//  Created by MacOS on 3/24/17.
//  Copyright © 2017 MacOS. All rights reserved.
//  

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "SDL2/SDL.h"
#include "SDL2_image/SDL_image.h"
#include "SDL2_ttf/SDL_ttf.h"
#include "updateArray.hpp"
#include "init.hpp"
#include "object.hpp"
#include "display.hpp"

using namespace std;

void createRandNum(int array[4][4]); // create a random number in array
int gameNotOver(int array[4][4]);
bool checkFullArrray(int array[4][4]);
int randomNumber();
int checkWinGame(int array[4][4]);

int main(int argc, const char * argv[]) {
    srand((unsigned int) time(NULL));
    
    SDL_Window *window = nullptr;
    SDL_Renderer *renderer = nullptr;
    SDL_Texture *screenTexture = nullptr;
    numTexture numbersTexture;
    SDL_Event event;
    TTF_Font *font = nullptr;
    string strScore;
    int score = 0;
    int array[4][4];
    int countEdit = 0;

    initSDL(window, renderer, font, numbersTexture);
    
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            array[i][j] = 0;
        }
    }
    
    createRandNum(array);
    createRandNum(array);
    
    renderArray(array, window, numbersTexture, screenTexture, renderer);
    SDL_RenderPresent(renderer);
    
    while (gameNotOver(array)) {
        SDL_Delay(10);
        if ( SDL_WaitEvent(&event) == 0) continue;
        if (event.type == SDL_QUIT) {
            quitSDL(window, renderer, screenTexture);
            return 0;
        }
        if (event.type == SDL_KEYDOWN) {
            switch (event.key.keysym.sym) {
                case SDLK_DOWN:
                    updateDown(array, countEdit, score);
                    break;
                case SDLK_UP:
                    updateUp(array, countEdit, score);
                    break;
                case SDLK_LEFT:
                    updateLeft(array, countEdit, score);
                    break;
                case SDLK_RIGHT:
                    updateRight(array, countEdit, score);
                    break;
                default:
                    break;
            }
            if (countEdit < 4) {
                createRandNum(array);
            }
        }
        renderArray(array, window, numbersTexture, screenTexture, renderer);
        displayScore(renderer, font, strScore, score);
        renderWinGame(array, numbersTexture, screenTexture, window, renderer);
        SDL_RenderPresent(renderer);
    }
    SDL_Delay(1000);
    renderLoseGame(array, numbersTexture, screenTexture, window, renderer);
    SDL_RenderPresent(renderer);
    SDL_Delay(1000);
    waitUntilKeyPressed();
    
    quitSDL(window, renderer, screenTexture);
    return 0;
}

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
