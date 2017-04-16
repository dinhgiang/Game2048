//
// object.hpp
// Game 2048
//
//  Created by MacOS on 04/12/17.
//  Copyright © 2017 MacOS. All rights reserved.
//

#ifndef object_hpp
#define object_hpp

#include <iostream>
using namespace std;

struct numTexture {
    SDL_Texture* empty   = nullptr;
    SDL_Texture* num2    = nullptr;
    SDL_Texture* num4    = nullptr;
    SDL_Texture* num8    = nullptr;
    SDL_Texture* num16   = nullptr;
    SDL_Texture* num32   = nullptr;
    SDL_Texture* num64   = nullptr;
    SDL_Texture* num128  = nullptr;
    SDL_Texture* num256  = nullptr;
    SDL_Texture* num512  = nullptr;
    SDL_Texture* num1024 = nullptr;
    SDL_Texture* num2048 = nullptr;
    SDL_Texture* num4096 = nullptr;
    SDL_Texture* num8192 = nullptr;
    SDL_Texture* win     = nullptr;
    SDL_Texture* lose    = nullptr;
};

const int SCREEN_WIDTH    = 600;
const int SCREEN_HEIGHT   = 700;
const string WINDOW_TITLE = "Game 2048";

const string EMPTY_IMG_PATH   = "Images/empty.png";
const string NUM2_IMG_PATH    = "Images/num2.png";
const string NUM4_IMG_PATH    = "Images/num4.png";
const string NUM8_IMG_PATH    = "Images/num8.png";
const string NUM16_IMG_PATH   = "Images/num16.png";
const string NUM32_IMG_PATH   = "Images/num32.png";
const string NUM64_IMG_PATH   = "Images/num64.png";
const string NUM128_IMG_PATH  = "Images/num128.png";
const string NUM256_IMG_PATH  = "Images/num256.png";
const string NUM512_IMG_PATH  = "Images/num512.png";
const string NUM1024_IMG_PATH = "Images/num1024.png";
const string NUM2048_IMG_PATH = "Images/num2048.png";
const string NUM4096_IMG_PATH = "Images/num4096.png";
const string NUM8192_IMG_PATH = "Images/num8192.png";
const string WIN_IMG_PATH     = "Images/win.png";
const string LOSE_IMG_PATH    = "Images/lose.png";

const string FONT_SCORE_PATH    = "Fonts/TimesNewRoman.ttf";
const string FONT_CONTINUE_PATH = "Fonts/lazy.ttf";

const int FONT_SCORE_SIZE    = 32;
const int FONT_CONTINUE_SIZE = 50;

const SDL_Color CYAN_COLOR   = {  0, 255, 255};
const SDL_Color BLUE_COLOR   = {  0,   0, 255};
const SDL_Color ORANGE_COLOR = {255, 165,   0};
const SDL_Color YELLOW_COLOR = {255, 255,   0};
const SDL_Color LIME_COLOR   = {0  , 255,   0};
const SDL_Color PURPLE_COLOR = {128,   0, 128};
const SDL_Color RED_COLOR    = {255,   0,   0};
const SDL_Color WHITE_COLOR  = {255, 255, 255};
const SDL_Color BLACK_COLOR  = {  0,   0,   0};
const SDL_Color GREEN_COLOR  = {  0, 128,   0};

#endif /* object_hpp */