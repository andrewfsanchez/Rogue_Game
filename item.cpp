#include "item.h"

using namespace std;

Item::Item()
{
	//Don't know what the default item values should be. Maybe there should be a constructor with a name parameter that sets stats for each type of item differently. 
	
	healthMod = 0;
	speedMod = 0;
	defenseMod = 0;
	attackMod = 0;
	regenMod = 0;
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
