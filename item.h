#include "Object.h"

#ifndef ITEM_H
#define ITEM_H


using namespace std;

class Item: public Object
{
	public:
		
		Item();
		Item(string, int, int, int, int, int, bool, bool, bool);
		int getHealthMod();
		int getSpeedMod();
		int getDefenseMod();
		int getAttackMod();
		int getRegenMod();
		string getName();
		bool isWeapon();
		bool isArmor();
		bool isConsumable();
		bool isEquipped();
		void equip();
		void unequip();


		string getSymbol();
		bool isEnemy();
		bool isWall();
		bool isItem();
		bool isDoor();
		
	private:
		
		string name;
		int healthMod;
		int speedMod;
		int defenseMod;
		int attackMod;
		int regenMod;

		bool armor;
		bool weapon;
		bool consumable;

		bool equipped;
};

#endif
