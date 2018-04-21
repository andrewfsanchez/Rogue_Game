
#include "item.h"


Item::Item(string id, int h, int s, int d, int a, int r)
{
	//Don't know what the default item values should be. Maybe there should be a constructor with a name parameter that sets stats for each type of item differently. 
	
	name = id;
	healthMod = h;
	speedMod = s;
	defenseMod = d;
	attackMod = a;
	regenMod = r;
}

int Item::getHealthMod()
{
	return healthMod;
}

int Item::getSpeedMod()
{
	return speedMod;
}

int Item::getDefenseMod()
{
	return defenseMod;
}

int Item::getAttackMod()
{
	return attackMod;
}

int Item::getRegenMod()
{
	return regenMod;
}

string Item::getName()
{
	return name;
}

string Item::getSymbol()
{
	return " I ";
}
bool Item::isEnemy()
{
	return false;
}
bool Item::isWall()
{
	return false;
}
bool Item::isItem()
{
	return true;
}
