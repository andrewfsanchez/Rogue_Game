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

	Item weapon;
	Item armor;


	Object* player;
	Node grid[30][30];
	int difficulty;
	int floor;
	
	//Vector for test items
	vector<Item> items;
	vector<Enemy> Enemy;
	vector<Item> inventory;

};

#endif // !GAME_H
