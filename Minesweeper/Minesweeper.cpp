#include "Minesweeper.h"
#include "Map.h"

void Minesweeper:: creating_map ()
{
	display.resize(length);
	data.resize(length);
	for (int i = 0; i < length; i++)
	{
		display[i].resize(width);
		data[i].resize(width);
		for (int j = 0; j < width; j++)
		{
			display[i][j] = '*';
			data[i][j] = 0;
		}
	}
}
void Minesweeper:: processing_bomb ()
{
	// Creating Bomb !
	srand(time(NULL));

	int x = 0, y = 0;
	for (int i = 0; i < bomb; i++)
	{
		do
		{
			x = rand() % length;
			y = rand() % width;
		}
		while (data[x][y] == BOMB);
		data[x][y] = BOMB;
	}

	// Counting bomb around area have coordinate (i, j) !
	for (int i = 0; i < length; i++)
		for (int j = 0; j < width; j++)
			if (data[i][j] != BOMB)
				for (int a = i-1; a <= i+1; a++)
					if (0 <= a && a < length)
						for (int b = j-1; b <= j+1; b++)
							if (0 <= b && b < width && data[a][b] == BOMB) data[i][j]++;
}
void Minesweeper:: open (int x, int y, bool& aLive)
{
	if (data[x][y] == BOMB)
	{
		SDL_Window* window = SDL_CreateWindow("Minesweeper", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, 0);
		SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
		SDL_Surface* surface = IMG_Load("Minesweeper.bmg");
		SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
		SDL_Rect picture;
		picture.x = (data[x][y])*32; picture.y = 0; picture.h = 32; picture.w = 32;
		SDL_Rect screen;
        screen.x = x*50; screen.y = y*50; screen.h = 50; screen.w = 50;
        SDL_RenderCopy(renderer, texture, &picture, &screen);
        SDL_RenderPresent(renderer);
		//aLive = false;
	}
	else extend (x, y);
}
void Minesweeper:: extend (int x, int y)
{
	if (data[x][y] != 0)
	{
		SDL_Window* window = SDL_CreateWindow("Minesweeper", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, 0);
		SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
		SDL_Surface* surface = IMG_Load("Minesweeper.bmg");
		SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
		SDL_Rect picture;
		picture.x = (data[x][y])*32; picture.y = 0; picture.h = 32; picture.w = 32;
		SDL_Rect screen;
        screen.x = x*50; screen.y = y*50; screen.h = 50; screen.w = 50;
        SDL_RenderCopy(renderer, texture, &picture, &screen);
        SDL_RenderPresent(renderer);
		return;
	}
	else
	{
		SDL_Window* window = SDL_CreateWindow("Minesweeper", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, 0);
		SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
		SDL_Surface* surface = IMG_Load("Minesweeper.bmg");
		SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
		SDL_Rect picture;
		picture.x = (data[x][y])*32; picture.y = 0; picture.h = 32; picture.w = 32;
		SDL_Rect screen;
        screen.x = x*50; screen.y = y*50; screen.h = 50; screen.w = 50;
        SDL_RenderCopy(renderer, texture, &picture, &screen);
        SDL_RenderPresent(renderer);
		for (int i = -1; i < 2; i++)
			if (i != 0 && 0 <= x+i && x+i < length)
				for (int j = -1; j < 2; j++)
					if (j != 0 && 0 <= j+y && j+y < width)
						if (picture.x == 320) extend(x+i, y+j);
	}
}
void Minesweeper:: print ()
{
	for (int i = 0; i < length; i++)
	{
		for (int j = 0; j < width; j++)
			cout << display[i][j] << " ";
		cout << endl;
	}
}
