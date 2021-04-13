#include "Map.h"

void Map (Minesweeper test)
{
    SDL_Window* window = SDL_CreateWindow("Minesweeper", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, 0);
    SDL_Renderer* render =  SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    SDL_Surface* load = IMG_Load("Minesweeper.bmp");
    SDL_Texture* texture = SDL_CreateTextureFromSurface(render, load);
    SDL_Rect picture; SDL_Rect screen;
    picture.x = 320; picture.y = 0; picture.w = 32; picture.h = 32;
    for (int i = 0; i < 9; i++)
        for (int j = 0; j < 9; j++)
        {
            screen.x = i*50; screen.y = j*50; screen.h = 50; screen.w = 50;
            SDL_RenderCopy(render, texture, &picture, &screen);
            SDL_RenderPresent(render);
        }

    SDL_Event e;
    SDL_Rect filled_rect;
    filled_rect.x = 400; filled_rect.y = 300;
    filled_rect.w = 16; filled_rect.h = 12;
    while (true)
    {
        SDL_Delay(10);
        if (SDL_WaitEvent(&e) == 0) continue;
        if (e.type == SDL_QUIT) break;
        if (e.type == SDL_MOUSEBUTTONDOWN)
        {
            filled_rect.x = e.button.x;
            filled_rect.y = e.button.y;
            if (e.button.button == SDL_BUTTON_LEFT) refreshScreen(window, render, filled_rect, true, test);
            else refreshScreen(window, render, filled_rect, false, test);
        }
    }

    for (int i = 0; i < 9; i++)
        for (int j = 0; j < 9; j++)
            {
                picture.x = (test.data[i][j])*32; picture.y = 0; picture.w = 32; picture.h = 32;
                screen.x = i*50; screen.y = j*50; screen.h = 50; screen.w = 50;
                SDL_RenderCopy(render, texture, &picture, &screen);
                SDL_RenderPresent(render);
            }
    while (true)
    {
        SDL_Delay(10);
        if (SDL_WaitEvent(&e) == 0) continue;
        if (e.type == SDL_QUIT) break;
    }

}
void refreshScreen (SDL_Window* window, SDL_Renderer* renderer, const SDL_Rect& filled_rect, const bool leftMouse, Minesweeper test)
{
/*
    SDL_Surface* surface = IMG_Load("Minesweeper.bmp");
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);

    SDL_Rect picture;
    picture.x = (test.data[filled_rect.x/50][filled_rect.y/50])*32;
    picture.y = 0; picture.h = 32; picture.w = 32;

    SDL_Rect screen;
    screen.x = (filled_rect.x/50)*50;
    screen.y = (filled_rect.y/50)*50;
    screen.h = 50; screen.w = 50;

    SDL_RenderCopy(renderer, texture, &picture, &screen);
    SDL_RenderPresent(renderer);
*/
    bool aLive = true;
    test.open(filled_rect.x/50, filled_rect.y/50, aLive);
}

