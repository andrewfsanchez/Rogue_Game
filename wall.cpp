#include "wall.h"

Wall::Wall() {}
char Wall::getSymbol()
{
	return '|';
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
