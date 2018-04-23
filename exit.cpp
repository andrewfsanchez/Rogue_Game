#include "exit.h"

Exit::Exit() {}
string Exit::getSymbol()
{
	return " > ";
}
bool Exit::isEnemy()
{
	return false;
}
bool Exit::isItem()
{
	return false;
}
bool Exit::isWall()
{
	return false;
}
bool Exit::isDoor()
{
	return false;
}
bool Exit::isExit()
{
	return true;
}
