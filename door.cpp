#include "door.h"

Door::Door()
{
	opened = false;
}
string Door::getSymbol()
{
	if (!opened)
		return " + ";
	else
		return " . ";
}
bool Door::isDoor()
{
	return true;
}
bool Door::isEnemy()
{
	return false;
}
bool Door::isItem()
{
	return false;
}
bool Door::isWall()
{
	return false;
}
bool Door::isExit()
{
	return false;
}

bool Door::isPlayer()
{
	return false;
}

void Door::open()
{
	opened = true;
}
bool Door::isOpen()
{
	return opened;
}

