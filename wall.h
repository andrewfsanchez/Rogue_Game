#include "Object.h"

#ifndef WALL_H
#define WALL_H

class Wall: public Object
{
public:
	Wall();
	char getSymbol();
	bool isEnemy();
	bool isWall();
	bool isItem();
};
#endif