//
//  init.cpp
//  Game2048
//
//  Created by MacOS on 3/26/17.
//  Copyright © 2017 MacOS. All rights reserved.
//

#include "init.hpp"

void logSDLError(ostream& os, const string& msg, bool fatal) {
    os << msg << "Error: " << SDL_GetError() << endl;
    if (fatal) {
        SDL_Quit();
        exit(1);
    }
}

void initSDL(SDL_Window* &window, SDL_Renderer* &renderer, TTF_Font* &fontScore, TTF_Font* &fontContinue, numTexture &numbersTexture) {
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        logSDLError(cout, "SDL_Init", true);
    }
    SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1");
    
    window = SDL_CreateWindow(WINDOW_TITLE.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if (window == NULL) {
        logSDLError(cout, "CreateWindow", true);
    }
    
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == NULL) {
        logSDLError(cout, "CreateRenderer", true);
    }
    
    int imgFlags = IMG_INIT_PNG;
    if( !( IMG_Init( imgFlags ) & imgFlags ) )
    {
        logSDLError(cout, "Initialize PNG loading", true);
    }
    
    if (TTF_Init() < 0) {
        cout << "Error: " << TTF_GetError() << endl;
    } 
    
    fontScore = TTF_OpenFont(FONT_SCORE_PATH.c_str(), FONT_SCORE_SIZE);
    if (fontScore == NULL) {
        cout << "Error";
    }
    
    fontContinue = TTF_OpenFont(FONT_CONTINUE_PATH.c_str(), FONT_CONTINUE_SIZE);
    if (fontContinue == NULL) {
        cout << "Error";
    }

    if( !loadMedia(numbersTexture, renderer))
    {
        cout << "Failed to load media!" << endl;
    }
}

void quitSDL(SDL_Window* &window, SDL_Renderer* &renderer, SDL_Texture* &screenTexture) {
    SDL_DestroyTexture(screenTexture);
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);

    SDL_Quit();
    IMG_Quit();
    TTF_Quit();
}

SDL_Texture* loadTexture(string filePath, SDL_Renderer* &renderer)
{
    SDL_Texture* texture = NULL;
    SDL_Surface* surface = IMG_Load(filePath.c_str());
    if (surface == NULL)
        cout << "Error: " << SDL_GetError() << endl;
    else
    {
        texture = SDL_CreateTextureFromSurface(renderer, surface);
        if (texture == NULL)
            cout << "Error: " << SDL_GetError() << endl;
    }
    SDL_FreeSurface(surface);
    return texture;
}



bool loadMedia(numTexture& numbersTexture, SDL_Renderer* &renderer) {
    bool success = true;
    
    numbersTexture.empty   = loadTexture(EMPTY_IMG_PATH, renderer);
    numbersTexture.num2    = loadTexture(NUM2_IMG_PATH, renderer);
    numbersTexture.num4    = loadTexture(NUM4_IMG_PATH, renderer);
    numbersTexture.num8    = loadTexture(NUM8_IMG_PATH, renderer);
    numbersTexture.num16   = loadTexture(NUM16_IMG_PATH, renderer);
    numbersTexture.num32   = loadTexture(NUM32_IMG_PATH, renderer);
    numbersTexture.num64   = loadTexture(NUM64_IMG_PATH, renderer);
    numbersTexture.num128  = loadTexture(NUM128_IMG_PATH, renderer);
    numbersTexture.num256  = loadTexture(NUM256_IMG_PATH, renderer);
    numbersTexture.num512  = loadTexture(NUM512_IMG_PATH, renderer);
    numbersTexture.num1024 = loadTexture(NUM1024_IMG_PATH, renderer);
    numbersTexture.num2048 = loadTexture(NUM2048_IMG_PATH, renderer);
    numbersTexture.num4096 = loadTexture(NUM4096_IMG_PATH, renderer);
    numbersTexture.num8192 = loadTexture(NUM8192_IMG_PATH, renderer);
    numbersTexture.win     = loadTexture(WIN_IMG_PATH, renderer);
    numbersTexture.lose    = loadTexture(LOSE_IMG_PATH, renderer);
    
    if (numbersTexture.empty == NULL || numbersTexture.num2 == NULL || numbersTexture.num4 == NULL || numbersTexture.num8 == NULL || numbersTexture.num16 == NULL || numbersTexture.num32 == NULL || numbersTexture.num64 == NULL || numbersTexture.num128 == NULL || numbersTexture.num256 == NULL || numbersTexture.num512 == NULL || numbersTexture.num1024 == NULL || numbersTexture.num2048 == NULL || numbersTexture.num4096 == NULL || numbersTexture.num8192 == NULL || numbersTexture.win == NULL|| numbersTexture.lose == NULL) {
        logSDLError(cout, "Failed to load PNG image!!!", true);
        success = false;
    }
    return success;
}
