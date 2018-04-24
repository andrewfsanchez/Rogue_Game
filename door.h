#include "Object.h"

#ifndef DOOR_H
#define DOOR_H

class Door: public Object
{
public:
	Door();
	string getSymbol();
	bool isEnemy();
	bool isWall();
	bool isItem();
	bool isDoor();
	bool isExit();
	bool isPlayer();

	bool isOpen();
	void open();
	
	
private:
	bool opened;
};

#endif