#include "exit.h"

Exit::Exit() 
{

}
string Exit::getSymbol()
{
	return " > ";
}
void Exit::setX(int x)
{
	X = x;
}
void Exit::setY(int x)
{
	Y = x;
}
int Exit::getX()
{
	return X;
}
int Exit::getY()
{
	return Y;
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
bool Exit::isPlayer()
{
	return false;
}
bool Exit::isExit()
{
	return true;
}
