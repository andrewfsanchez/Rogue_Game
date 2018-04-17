#include "Object.h"


#ifndef PLAYER_H
#define PLAYER_H

#include "item.h" 

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
		int getItem();
		void addItem(int x);
		void dropItem();
		void useItem();
		void regeneration();
		void levelUp();
		int getLevel();
		Player getPlayer(); //Location? 
		//void Attack(Enemy& target);
		void takeDamage(int damage);

		char getSymbol();
		bool isEnemy();
	
	private:
	
		int maxHealth;
		int currentHealth;
		int speed;
		int attack;
		int defense;
		int regen;
		int level;
		int turnsToRegen;
		Item inventory[20]; //Not used yet
};

#endif
