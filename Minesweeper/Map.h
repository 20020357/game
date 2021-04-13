#pragma once
#include "Minesweeper.h"
#include <SDL.h>
#include <SDL_image.h>

void Map (Minesweeper test);
void refreshScreen (SDL_Window* window, SDL_Renderer* renderer, const SDL_Rect& filled_rect, const bool leftMouse, Minesweeper test);
