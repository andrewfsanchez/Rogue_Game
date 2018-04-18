
#include "player.h"
using namespace std;

Player::Player()
{
	//Test values
	maxHealth = 15;
	currentHealth = maxHealth;
	speed = 2;
	defense = 0;
	attack = 4;
	regen = 1;
	level = 1;
	turnsToRegen = 2; 
}

int Player::getHealth()
{
	return currentHealth;
}

void Player::setHealth(int x)
{
	currentHealth = x;
}

int Player::getSpeed()
{
	return speed;
}

void Player::setSpeed(int x)
{
	speed = x;
}

int Player::getAttack()
{
	return attack;
}

void Player::setAttack(int x)
{
	attack = x;
}

int Player::getDefense()
{
	return defense;
}

void Player::setDefense(int x)
{
	defense = x;
}

int Player::getRegen()
{
	return regen;
}

void Player::setRegen(int x)
{
	regen = x;
}

/*int Player::getItem()
{
	//Not sure here.
}

void Player::addItem(int x)
{
	//Does this one add item to inventory? Should the parameter be an item?
}

void Player::dropItem()
{
	//Not sure what this does. Does the player discard items without using them?
}

void Player::useItem()
{
	//Again, need to figure out how items work first
}*/

void Player::regeneration()
{
	turnsToRegen--;
	
	while (turnsToRegen == 0)
	{
		if(currentHealth == maxHealth)
			turnsToRegen = 2; 
		
		else 
		{
			currentHealth = currentHealth + regen;
			turnsToRegen = 2;
		}
	}
}
		

void Player::levelUp()
{
	//Haven't discussed how this will work yet, so just a test.
	
	maxHealth = maxHealth + 5;
	speed = speed + 1;
	defense = defense + 1;
	attack = attack + 1;
	level++;
}

int Player::getLevel()
{
	return level;
}

/*void Player::Attack(Enemy& target)
{
	//Add the proper formula for damage, this was just a test.
	
	int enemyDef = target.getDefense();
	int damage = attack - enemyDef;
	target.takeDamage(damage);
} */

void Player::takeDamage(int damage)
{
	currentHealth = currentHealth - damage;
}
char Player::getSymbol()
{
	return '@';
}
bool Player::isEnemy()
{
	return false;
}
bool Player::isWall()
{
	return false;
}

bool Player::isItem()
{
	return false;
}


/*
Player::getPlayer()
{
	//Assuming this should return the player location. Not sure how this will be done yet.
}
*/
	
	

