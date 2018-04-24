#include "Object.h"

#ifndef EXIT_H
#define EXIT_H

class Exit : public Object
{
public:
	Exit();
	void setX(int x);
	void setY(int y);
	int getX();
	int getY();
	bool isExit();
	string getSymbol();
	bool isEnemy();
	bool isWall();
	bool isItem();
	bool isDoor();
	bool isPlayer();
	int X;
	int Y;
};
#endif
