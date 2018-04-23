
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

Enemy::Enemy()
{
	//Test values again
	health = 15;
	attack = 2;
	speed = 2;
	defense = 0;
	type = 0;
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

int Enemy::getSpeed()
{
	return speed;
}

int Enemy::getAttack()
{
	return attack;
}

int Enemy::getDefense()
{
	return defense;
}

int Enemy::getItem()
{
	//Still need to know how items work. Is this like what the enemy drops when killed?
	return item;
}

/*void Enemy::Attack(Player& target)
{
//Just a test, actual formula can be added later.
int playerDef = target.getDefense();
int damage = attack - playerDef;
target.takeDamage(damage);
} */

void Enemy::takeDamage(int damage)
{
	health = health - damage;
}

string Enemy::getSymbol()
{
	return " E ";
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

