#include "player.h"


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
	weapon;
	armor;
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

bool Player::isInvEmpty()
{
	return inventory.empty();
}

bool Player::isInvFull()
{
	return (inventory.size() == invMaxSize);
}

vector<Item> Player::getInventory()
{
	return inventory;
}

Item Player::getItem()
{
	return inventory[0];
}

Item Player::getItem(int itemIndex)
{
	 return inventory[itemIndex];
}

void Player::addItem(Item item)
{
	inventory.push_back(item);
}

void Player::dropItem()
{
	inventory.erase(inventory.begin() + 0);
}

void Player::dropItem(int itemIndex)
{
	inventory.erase(inventory.begin() + itemIndex);
}

void Player::useItem(Item x)
{
	attack = attack + x.getAttackMod();
	defense = defense + x.getDefenseMod();
	speed = speed + x.getSpeedMod();
	currentHealth = currentHealth + x.getHealthMod();
	if (currentHealth > maxHealth)
		currentHealth = maxHealth;	
	regen = regen + x.getRegenMod();
}

void Player::setWeapon(Item w)
{
	//Remove stat buffs from previously equipped weapon
	attack = attack - weapon.getAttackMod();
	defense = defense - weapon.getDefenseMod();
	speed = speed - weapon.getSpeedMod();
	maxHealth = maxHealth - weapon.getHealthMod();
	regen = regen - weapon.getRegenMod();
	
	//Set new weapon
	weapon = w;	
	
	//Apply new stat buff from newly equipped weapon
	attack = attack + weapon.getAttackMod();
	defense = defense + weapon.getDefenseMod();
	speed = speed + weapon.getSpeedMod();
	maxHealth = maxHealth + weapon.getHealthMod();
	regen = regen + weapon.getRegenMod();
}

Item Player::getWeapon()
{
	return weapon;
}

void Player::setArmor(Item a)
{
	//Remove stat buffs from previously equipped armor
	attack = attack - armor.getAttackMod();
	defense = defense - armor.getDefenseMod();
	speed = speed - armor.getSpeedMod();
	maxHealth = maxHealth - armor.getHealthMod();
	regen = regen - armor.getRegenMod();
	
	//Set new armor	
	armor = a;
	
	//Apply new stat buffs
	attack = attack + armor.getAttackMod();
	defense = defense + armor.getDefenseMod();
	speed = speed + armor.getSpeedMod();
	maxHealth = maxHealth + armor.getHealthMod();
	regen = regen + armor.getRegenMod();
}

Item Player::getArmor()
{
	return armor;
}

void Player::unequipWeapon()
{
	//remove stat buffs from equipped weapon
	attack = attack - weapon.getAttackMod();
	defense = defense - weapon.getDefenseMod();
	speed = speed - weapon.getSpeedMod();
	maxHealth = maxHealth - weapon.getHealthMod();
	regen = regen - weapon.getRegenMod();
	
	weapon = Item();
}

void Player::unequipArmor()
{
	//Remove stat buffs from equipped armor
	attack = attack - armor.getAttackMod();
	defense = defense - armor.getDefenseMod();
	speed = speed - armor.getSpeedMod();
	maxHealth = maxHealth - armor.getHealthMod();
	regen = regen - armor.getRegenMod();
	
	armor = Item();
}

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


/*
Player::getPlayer()
{
	//Assuming this should return the player location. Not sure how this will be done yet.
}
*/
	
	

