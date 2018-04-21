#include "node.cpp"
#include "player.cpp"
#include "enemy.cpp"
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
	void gameOver();
	
private:
	//void makeNextFloor(int, int);
	void updateGrid();
	void clearGrid();
	void deleteGrid();

	void playerMove();
	void playerDrop();
	void playerUseItem();
	void moveEnemies();
	



	Player player;
	Node grid[30][30];
	int difficulty;
	int floor;


};

#endif // !GAME_H
