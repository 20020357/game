#pragma once
#include <bits/stdc++.h>
#include <windows.h>
#define BOMB 9
using namespace std;

struct Minesweeper
{
	int length = 9, width = 9;
	int bomb = 10;
	vector <vector<char>> display;
	vector <vector<int>> data;
	void creating_map ();
	void processing_bomb ();
	void open (int x, int y, bool& aLive);
	void extend (int x, int y);
	void print ();
};
