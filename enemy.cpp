
#include "enemy.h"

/*
NOTES:
- Should enemy level be considered when creating an enemy?
- If so, should they be based on stage in the game or player level?
- Will there be different types of enemies? Should some have different starting stats than others?

- To accomplish this we could maybe pass "type" and "level" parameters when creating an enemy

i.e.
Enemy (string type, int level)
{
if type == bat
{
bat stats here
}
else if type == spider
{
spider stats here
}
}

NOTE: I don't actually know if there will be different types of enemies or what they will be.
*/

Enemy::Enemy(int x, int y)
{
	//Test values again
	health = 15;
	attack = 0;
	defense = 0;
	type = 0;
	exp = 0;
	posX = x;
	posY = y;
	
}

int Enemy::getHealth()
{
	return health;
}

void Enemy::setHealth(int x)
{
	health = x;
}

void Enemy::setType(int x)
{
	type = x;
}

int Enemy::getType()
{
	return type;
}

int Enemy::getX()
{
	return posX;
}

void Enemy::setX(int x)
{
	posX = x;
}

int Enemy::getY()
{
	return posY;
}

void Enemy::setY(int y)
{
	posY = y;
}

int Enemy::getAttack()
{
	return attack;
}

int Enemy::getDefense()
{
	return defense;
}

void Enemy::takeDamage(int playerAtk)
{
	health = health - (playerAtk*10)/(10 + defense);
}

string Enemy::getSymbol()
{
	if (type == 1)
	{

		return " B ";     //Bat

	}
	else if (type == 2)
	{

		return " S ";     //Spider

	}

	else if (type == 3)
	{

		return " Z ";      //Zombie
	
	}

}

void Enemy::setExp(int x)
{

	exp = x;

}

int Enemy::getExperience()
{
	
	return exp;

}	
		
bool Enemy::isEnemy()
{
	return true;
}
bool Enemy::isWall()
{
	return false;
}
bool Enemy::isItem()
{
	return false;
}
bool Enemy::isDoor()
{
	return false;
}
bool Enemy::isExit()
{
	return false;
}
