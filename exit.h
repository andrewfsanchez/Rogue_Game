#include "Object.h"

#ifndef EXIT_H
#define EXIT_H

class Exit : public Object
{
public:
	bool isExit();
	string getSymbol();
	bool isEnemy();
	bool isWall();
	bool isItem();
	bool isDoor();

#endif
