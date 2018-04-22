#include "door.h"

Door::Door()
{
	open = false;
}
string Door::getSymbol()
{
	if(!open)
		return " + ";
	else
		return " . "
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

void Door::open()
{
	open = true;
}
bool Door::isOpen()
{
	return open;
}

