#include "Object.h"

#ifndef WALL_H
#define WALL_H

class Wall: public Object
{
public:
	Wall();
	string getSymbol();
	bool isEnemy();
	bool isWall();
	bool isItem();
	bool isDoor();
};
#endif