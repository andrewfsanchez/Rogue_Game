#include "DungeonLevel.h"

#include <iostream>
#include <vector>


#ifndef GAME_H
#define GAME_H

class Game
{
public:
	Game(int);
	void printGrid();
	void playerAction();
	void gameOver();
	void startGame();
	void makeNextLevel();

	void useItem(Item, Object*);
	void setWeapon(Item w, Object*);
	void setArmor(Item a, Object*);
	void setAI(bool ai);
	
	
private:
	//void makeNextFloor(int, int);
	
	void updateGrid();
	void clearGrid();
	void deleteGrid();

	void playerMove();
	void playerDrop();
	void playerUseItem();
	void moveEnemies();
	void eraseEnemies();

	Item weapon;
	Item armor;

	Dungeon level;

	Object* player;
	Object* x = new Exit;
	Node grid[30][30];
	int difficulty;
	int floor;
	bool AI;

	vector<Item> items; //Vector for test items
	vector<Enemy> enemies;
	vector<Item> inventory;

};

#endif // !GAME_H
