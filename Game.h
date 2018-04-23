#include "node.cpp"
#include "player.cpp"
#include "enemy.cpp"
#include "Object.h"
#include "item.cpp"
#include "DungeonLevel.cpp"
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
	
	void useItem(Item, Object*);
	Item getWeapon();
	Item getArmor();
	void setWeapon(Item w, Object*);
	void setArmor(Item a, Object*);
	
private:
	//void makeNextFloor(int, int);
	void updateGrid();
	void clearGrid();
	void deleteGrid();

	void playerMove();
	void playerDrop();
	void playerUseItem();
	void moveEnemies();
	void generateEnemies();

	Item weapon;
	Item armor;


	Object* player;
	Node grid[30][30];
	int difficulty;
	int floor;
	
	//Vector for test items
	vector<Item> items;
	vector<Enemy> Enemy;

};

#endif // !GAME_H
