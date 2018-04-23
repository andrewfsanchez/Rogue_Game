#include "wall.h"

Wall::Wall() {}
string Wall::getSymbol()
{
	return " # ";
}
bool Wall::isEnemy()
{
	return false;
}
bool Wall::isItem()
{
	return false;
}
bool Wall::isWall()
{
	return true;
}
bool Wall::isDoor()
{
	return false;
}
bool Wall::isExit()
{
	return false;
}
