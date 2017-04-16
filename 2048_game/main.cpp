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
#include "logic.hpp"
using namespace std;

bool tryAgain(SDL_Renderer* &renderer, TTF_Font* &fontContinue, SDL_Event& event, SDL_Window* &window, SDL_Texture* &screenTexture) {
    displayContinue(renderer, fontContinue);
    SDL_RenderPresent(renderer);
    
    do { 
        SDL_Delay(10);
        if (SDL_WaitEvent(&event) == 0) { continue; }
        switch (event.key.keysym.sym) {
            case SDLK_y :
                return true;
            case SDLK_n:
            case SDL_QUIT:
                quitSDL(window, renderer, screenTexture);
                break;
            default:
                break;
        }
    } while (event.key.keysym.sym != SDLK_y && event.key.keysym.sym != SDLK_n && event.type != SDL_QUIT);
    
    return false;
}
bool playAGame(SDL_Window* &window, SDL_Renderer* &renderer, numTexture &numbersTexture, SDL_Event &event, SDL_Texture* &screenTexture, TTF_Font* &fontScore) {
    string strScore;
    int score = 0;
    int array[4][4];
    int countEdit = 0;
    
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            array[i][j] = 0;
        }
    }
    
    createRandNum(array);
    createRandNum(array);
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    renderArray(array, window, numbersTexture, screenTexture, renderer);
    SDL_RenderPresent(renderer);
    
    while (gameNotOver(array)) {
        SDL_Delay(10);
        if ( SDL_WaitEvent(&event) == 0) continue;
        if (event.type == SDL_QUIT) {
            quitSDL(window, renderer, screenTexture);
            return true;
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
                    continue;
            }
            if (countEdit < 4) {
                createRandNum(array);
            }
        }
        renderArray(array, window, numbersTexture, screenTexture, renderer);
        displayScore(renderer, fontScore, strScore, score);
        renderWinGame(array, numbersTexture, screenTexture, window, renderer);
        SDL_RenderPresent(renderer);
    }
    SDL_Delay(1000);
    renderLoseGame(array, numbersTexture, screenTexture, window, renderer);
    SDL_RenderPresent(renderer);
    SDL_Delay(1000);
    
    return false;
}

int main(int argc, const char * argv[]) {
    srand((unsigned int) time(NULL));
    
    SDL_Window *window = nullptr;
    SDL_Renderer *renderer = nullptr;
    SDL_Texture *screenTexture = nullptr;
    numTexture numbersTexture;
    SDL_Event event;
    TTF_Font *fontScore = nullptr;
    TTF_Font *fontContinue = nullptr;
    
    initSDL(window, renderer, fontScore, fontContinue, numbersTexture);
    
    
    do {
        if ( playAGame(window, renderer, numbersTexture, event, screenTexture, fontScore) ) break;
    } while ( tryAgain(renderer, fontContinue, event, window, screenTexture) );
    
    quitSDL(window, renderer, screenTexture);
    return 0;
}

