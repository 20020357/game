#include <iostream>
#include "Map.h"
#include "Minesweeper.h"


int main(int argc, char *argv[])
{
    bool aLive = true;
	Minesweeper test;
	test.creating_map();
	test.processing_bomb();
	Map(test);
	return 0;
}
