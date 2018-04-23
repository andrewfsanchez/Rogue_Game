//
// Created by Ben on 4/20/2018.
//

#ifndef UNTITLED_DUNGEONLEVEL_H
#define UNTITLED_DUNGEONLEVEL_H
#include <random>
#include <vector>
#include <iostream>
#include "exit.h"
#include "player.h"
#include "enemy.h"
#include "item.h"
#include "node.h"
#include "wall.h"
#include "door.h"

class Dungeon
{
public:
	int randomNumberGenerator(int max, int min);
	int randRoomWidth(int numRooms);
	int randRoomLength(int numRooms);
	int numRoomsGenerator();
	int randDirectionGenerator();
    void makeRoom(int numRooms, int width, int length, Node grid[30][30]);
	void makeStartRoom(int width, int length, Node grid[30][30], Object*);
	void printRoom(int direction, int width, int length, int row, int col, Node grid[30][30]);
	bool isValidDirection(int direction, int width, int length, int row, int col, Node grid[30][30]);
	bool isEdge(Node grid[30][30], int i, int k);
	bool roomMadeHere();
	void dungeonBuild(Node grid[30][30], Object*);
	void addEnemiesToMap(Node grid[30][30], int difficulty, vector<Enemy>&, int floor);

	

private:

};

#endif //UNTITLED_DUNGEONLEVEL_H
