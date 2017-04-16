//
//  init.hpp
//  Game2048
//
//  Created by MacOS on 3/26/17.
//  Copyright © 2017 MacOS. All rights reserved.
//

#ifndef init_hpp
#define init_hpp

#include <iostream>
#include "SDL2/SDL.h"
#include "SDL2_image/SDL_image.h"
#include "SDL2_ttf/SDL_ttf.h"
#include "object.hpp"

using namespace std;

void initSDL(SDL_Window* &window, SDL_Renderer* &renderer, TTF_Font* &fontScore, TTF_Font* &fontContinue, numTexture &numbersTexture);
void logSDLError(ostream& os, const string& msg, bool fatal = false);
void quitSDL(SDL_Window* &window, SDL_Renderer* &renderer, SDL_Texture* &screenTexture);
bool loadMedia(numTexture& numbersTexture, SDL_Renderer* &renderer);
SDL_Texture* loadTexture(string filePath, SDL_Renderer* &renderer);

#endif /* init_hpp */