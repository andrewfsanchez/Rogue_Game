#include "node.cpp"
#include "player.cpp"
#include "Object.h"
#include <iostream>


#ifndef GAME_H
#define GAME_H

class Game
{
public:
	Game(int);
	void printGrid();
	void playerAction();
	
private:
	void makeLevel();
	void updateGrid();
	
	void clearGrid();



	Player player;
	Node grid[30][30];
	int difficulty;
	int floor;


};

#endif // !GAME_H
