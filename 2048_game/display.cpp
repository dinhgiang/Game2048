//
//  display.cpp
//  2048_game
//
//  Created by MacOS on 4/13/17.
//  Copyright © 2017 MacOS. All rights reserved.
//

#include "display.hpp"

string toStringScore(const int num) {
    stringstream ss;
    ss << "Your score: ";
    ss << num;
    string str = ss.str();
    return str;
}

void displayScore(SDL_Renderer* &renderer, TTF_Font* &font, string strScore, int score){
    strScore = toStringScore(score);
    SDL_Surface *textSurface;
    textSurface = TTF_RenderText_Solid(font, strScore.c_str(), YELLOW_COLOR);
    SDL_Texture *text = SDL_CreateTextureFromSurface(renderer, textSurface);
    
    SDL_Rect textRect;
    SDL_QueryTexture(text, NULL, NULL, &textRect.w, &textRect.h);
    textRect.x = SCREEN_WIDTH / 2 - textRect.w /2;
    textRect.y = 0;
    
    SDL_RenderCopy(renderer, text, NULL, &textRect);
    
    SDL_FreeSurface(textSurface);
    SDL_DestroyTexture(text);
}

void renderArray(int array[4][4], SDL_Window* window, const numTexture& numbersTexture, SDL_Texture* screenTexture, SDL_Renderer* &renderer) {
    SDL_RenderClear(renderer);
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            SDL_Rect image;
            image.x = j * 150;
            image.y = SCREEN_HEIGHT - 600 + i * 150;
            image.w = 150;
            image.h = 150;
            
            switch (array[i][j]) {
                case 0:
                    SDL_RenderCopy(renderer, numbersTexture.empty, nullptr, &image);
                    break;
                case 2:
                    SDL_RenderCopy(renderer, numbersTexture.num2, nullptr, &image);
                    break;
                case 4:
                    SDL_RenderCopy(renderer, numbersTexture.num4, nullptr, &image);
                    break;
                case 8:
                    SDL_RenderCopy(renderer, numbersTexture.num8, nullptr, &image);
                    break;
                case 16:
                    SDL_RenderCopy(renderer, numbersTexture.num16, nullptr, &image);
                    break;
                case 32:
                    SDL_RenderCopy(renderer, numbersTexture.num32, nullptr, &image);
                    break;
                case 64:
                    SDL_RenderCopy(renderer, numbersTexture.num64, nullptr, &image);
                    break;
                case 128:
                    SDL_RenderCopy(renderer, numbersTexture.num128, nullptr, &image);
                    break;
                case 256:
                    SDL_RenderCopy(renderer, numbersTexture.num256, nullptr, &image);
                    break;
                case 512:
                    SDL_RenderCopy(renderer, numbersTexture.num512, nullptr, &image);
                    break;
                case 1024:
                    SDL_RenderCopy(renderer, numbersTexture.num1024, nullptr, &image);
                    break;
                case 2048:
                    SDL_RenderCopy(renderer, numbersTexture.num2048, nullptr, &image);
                    break;
                case 4096:
                    SDL_RenderCopy(renderer, numbersTexture.num4096, nullptr, &image);
                    break;
                case 8192:
                    SDL_RenderCopy(renderer, numbersTexture.num8192, nullptr, &image);
                    break;
                default:
                    break;
            }
        }
    }
}

void renderWinGame(int array[4][4], const numTexture& numbersTexture, SDL_Texture* screenTexture, SDL_Window* window, SDL_Renderer* &renderer) {
    int i, j;
    static int k2048 = 1, k4096 = 1, k8192 = 1; // biến để load ảnh win game 1 lần;
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            if (array[i][j] == 2048 && k2048==1) {
                SDL_RenderCopy(renderer, numbersTexture.win, nullptr, nullptr);
                SDL_RenderPresent(renderer);
                SDL_Delay(3000);
                k2048 = 0;
                return ;
            }
            if (array[i][j] == 4096 && k4096==1) {
                SDL_RenderCopy(renderer, numbersTexture.win, nullptr, nullptr);
                SDL_RenderPresent(renderer);
                SDL_Delay(3000);
                k4096 = 0;
                return ;
            }
            if (array[i][j] == 8192 && k8192==1) {
                SDL_RenderCopy(renderer, numbersTexture.win, nullptr, nullptr);
                SDL_RenderPresent(renderer);
                SDL_Delay(3000);
                k8192 = 0;
                return ;
            }
        }
    }        
}

void renderLoseGame(int array[4][4], const numTexture& numbersTexture, SDL_Texture* screenTexture,  SDL_Window* window, SDL_Renderer* &renderer) {
    SDL_RenderCopy(renderer, numbersTexture.lose, nullptr, nullptr);
}

void displayContinue(SDL_Renderer* &renderer, TTF_Font* &fontContinue) {
    SDL_Surface *textSurface;
    textSurface = TTF_RenderText_Solid(fontContinue, "Play again?(y/n)", GREEN_COLOR);
    
    SDL_Texture *text = SDL_CreateTextureFromSurface(renderer, textSurface);
    
    SDL_Rect rectContinueText;
    SDL_QueryTexture(text, NULL, NULL, &rectContinueText.w, &rectContinueText.h);
    rectContinueText.x = SCREEN_WIDTH / 2 - rectContinueText.w / 2;
    rectContinueText.y = SCREEN_HEIGHT / 2 - rectContinueText.h / 2;
    
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    
    SDL_RenderFillRect (renderer, &rectContinueText);
    
    SDL_RenderCopy(renderer, text, NULL, &rectContinueText);
    
    SDL_FreeSurface(textSurface);
    SDL_DestroyTexture(text);
    textSurface = nullptr;
    text = nullptr;
}
