#ifndef ITEM_H
#define ITEM_H

using namespace std;

class Item
{
	public:
		
		Item();
		int getHealthMod();
		int getSpeedMod();
		int getDefenseMod();
		int getAttackMod();
		int getRegenMod();
		
	private:
		
		int healthMod;
		int speedMod;
		int defenseMod;
		int attackMod;
		int regenMod;
};

#endif
