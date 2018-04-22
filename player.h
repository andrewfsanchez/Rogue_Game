#include <vector>
#include "Object.h"
#include "item.h"
#include "item.cpp" 

#ifndef PLAYER_H
#define PLAYER_H

using namespace std;



class Player : public Object
{
	public:
		
		Player();
		int getHealth();
		void setHealth(int x);
		int getSpeed();
		void setSpeed(int x);
		int getAttack();
		void setAttack(int x);
		int getDefense();
		void setDefense(int x);
		int getRegen();
		void setRegen(int x);
		
		
		bool isInvEmpty();
		bool isInvFull();
		vector<Item> getInventory();
		Item getItem();
		Item getItem(int);
		void addItem(Item);
		void dropItem();
		void dropItem(int);
		
		void useItem(Item x);
		Item getWeapon();
		Item getArmor();
		void setWeapon(Item w);
		void setArmor(Item a);
		void unequipWeapon();
		void unequipArmor();
		
		void regeneration();
		void levelUp();
		int getLevel();
		Player getPlayer(); //Location? 
		//void Attack(Enemy& target);
		void takeDamage(int damage);
		void addExp(int);

		string getSymbol();
		bool isEnemy();
		bool isWall();
		bool isItem();
		bool isDoor();
	
	private:
		
		int maxHealth;
		int currentHealth;
		int speed;
		int attack;
		int defense;
		int regen;
		int level;
		int levelUpExp;
		int currentExp;
		int turnsToRegen;
		int invMaxSize = 20;
		vector<Item> inventory; //Not used yet
		Item weapon;
		Item armor;
};

#endif
