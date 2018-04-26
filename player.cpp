#include "player.h"
#include <iostream>

Player::Player()
{
	//Test values
	maxHealth = 15;
	currentHealth = maxHealth;
	defense = 2;
	attack = 5;
	regen = 1;
	level = 1;
	turnsToRegen = 3;

	x = 15;
	y = 15;

	currentExp = 0;
	levelUpExp = 15;
}

int Player::getHealth()
{
	return currentHealth;
}

int Player::getMaxHealth()
{
	return maxHealth;
}

void Player::setHealth(int x)
{
	currentHealth = x;
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

int Player::getX()
{
	return x;
}
void Player::setX(int set)
{
	x = set;
}
int Player::getY()
{
	return y;
}
void Player::setY(int set)
{
	y = set;
}


void Player::regeneration()
{
	turnsToRegen--;
	
	if (turnsToRegen == 0)
	{
		if(currentHealth == maxHealth)
			turnsToRegen = 3; 
		
		else 
		{
			currentHealth = currentHealth + regen;
			turnsToRegen = 3;
		}
	}
}
		
void Player::addExp(int add)
{
	currentExp += add;
	if (currentExp >= levelUpExp)
		levelUp();
}

int Player::getExp()
{
	return (levelUpExp - currentExp);
}

void Player::levelUp()
{
	cout << "Level Up!" << endl;
	maxHealth = maxHealth + 8;
	currentHealth = maxHealth;
	attack = attack + 5;
	defense = defense + 2;
	level++;

	levelUpExp = level*15;
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

void Player::takeDamage(int enemyAtk)
{
	currentHealth = currentHealth - (10*enemyAtk)/(10 + defense);
}
string Player::getSymbol()
{
	return " @ ";
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

bool Player::isDoor()
{
	return false;
}
bool Player::isExit()
{
	return false;
}

bool Player::isPlayer()
{
	return true;
}

	
	

