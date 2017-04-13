//
//  display.hpp
//  2048_game
//
//  Created by MacOS on 4/13/17.
//  Copyright © 2017 MacOS. All rights reserved.
//

#ifndef display_hpp
#define display_hpp

#include <iostream>
#include <sstream>
#include "SDL2/SDL.h"
#include "SDL2_image/SDL_image.h"
#include "SDL2_ttf/SDL_ttf.h"
#include "object.hpp"
using namespace std;

string toStringScore(const int num);
void displayScore(SDL_Renderer* &renderer, TTF_Font* &font, string strScore, int score);
void renderWinGame(int array[4][4], const numTexture& numbersTexture, SDL_Texture* screenTexture,  SDL_Window* window, SDL_Renderer* &renderer);
void renderLoseGame(int array[4][4], const numTexture& numbersTexture, SDL_Texture* screenTexture,  SDL_Window* window, SDL_Renderer* &renderer);
void renderArray(int array[4][4], SDL_Window* window, const numTexture& numbersTexture, SDL_Texture* screenTexture, SDL_Renderer* &renderer);

#endif /* display_hpp */
