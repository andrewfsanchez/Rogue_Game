#include "Object.h"

#ifndef ITEM_H
#define ITEM_H


using namespace std;

class Item: public Object
{
	public:
		
		Item(int, int, int, int, int);
		int getHealthMod();
		int getSpeedMod();
		int getDefenseMod();
		int getAttackMod();
		int getRegenMod();

		string getSymbol();
		bool isEnemy();
		bool isWall();
		bool isItem();
		
	private:
		
		int healthMod;
		int speedMod;
		int defenseMod;
		int attackMod;
		int regenMod;
};

#endif
