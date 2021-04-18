#include "Minesweeper.h"

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
void Minesweeper:: open (int x, int y, bool& aLive, SDL_Renderer* renderer, SDL_Texture* texture, SDL_Rect& picture, SDL_Rect& screen)
{
	if (data[x][y] == BOMB)
	{
		display[x][y] = 'X';
		picture.x = data[x][y]*32; picture.y = 0; picture.h = 32; picture.w = 32;
		screen.x = x*50; screen.y = y*50; screen.h = 50; screen.w = 50;
		print(renderer, texture, picture, screen);
		aLive = false;
	}
	else extend (x, y, renderer, texture, picture, screen);
}
void Minesweeper:: extend (int x, int y, SDL_Renderer* renderer, SDL_Texture* texture, SDL_Rect& picture, SDL_Rect& screen)
{
	if (data[x][y] != 0)
	{
		display[x][y] = data[x][y] + 48;

		picture.x = data[x][y]*32; picture.y = 0; picture.h = 32; picture.w = 32;
		screen.x = x*50; screen.y = y*50; screen.h = 50; screen.w = 50;
		print(renderer, texture, picture, screen);

		return;
	}
	else
	{
		display[x][y] = ' ';

		picture.x = data[x][y]*32; picture.y = 0; picture.h = 32; picture.w = 32;
		screen.x = x*50; screen.y = y*50; screen.h = 50; screen.w = 50;
		print(renderer, texture, picture, screen);
		for (int i = -1; i < 2; i++)
			if (i != 0 && 0 <= x+i && x+i < length)
				for (int j = -1; j < 2; j++)
					if (j != 0 && 0 <= j+y && j+y < width)
						if (display[x+i][y+j] == '*') extend(x+i, y+j, renderer, texture, picture, screen);

	}
}
void Minesweeper:: print (SDL_Renderer* renderer, SDL_Texture* texture, SDL_Rect& picture, SDL_Rect& screen)
{
	SDL_RenderCopy(renderer, texture, &picture, &screen);
    SDL_RenderPresent(renderer);
}
