#include "item.h"

//Default constructor for item, used in player equipment methods for unequipping and also for starting weapon and armor fields.
Item::Item()
{
	name = "NONE";
	healthMod = 0;
	speedMod = 0;
	speedMod = 0;
	defenseMod = 0;
	attackMod = 0;
	regenMod = 0;

	weapon = false;
	armor = false;
	consumable = false;
	equipped = false;
}
	
Item::Item(string id, int h, int s, int d, int a, int r, bool weap, bool arm, bool consume)
{
	//Don't know what the default item values should be. Maybe there should be a constructor with a name parameter that sets stats for each type of item differently. 
	
	name = id;
	healthMod = h;
	speedMod = s;
	defenseMod = d;
	attackMod = a;
	regenMod = r;

	weapon = weap;
	armor = arm;
	consumable = consume;
	equipped = false;
	
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

bool Item::isArmor()
{
	return armor;
}

bool Item::isWeapon()
{
	return weapon;
}

bool Item::isConsumable()
{
	return consumable;
}

bool Item::isEquipped()
{
	return equipped;
}

void Item::equip()
{
	equipped = true;
}

void Item::unequip()
{
	equipped = false;
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
