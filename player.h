#include <vector>
#include "Object.h"
#include "item.h" 

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
		Item getItem();
		Item getItem(int);
		void addItem(Item);
		void dropItem();
		void dropItem(int);
		//void useItem();
		
		void regeneration();
		void levelUp();
		int getLevel();
		Player getPlayer(); //Location? 
		//void Attack(Enemy& target);
		void takeDamage(int damage);

		char getSymbol();
		bool isEnemy();
		bool isWall();
		bool isItem();
	
	private:
		
		int maxHealth;
		int currentHealth;
		int speed;
		int attack;
		int defense;
		int regen;
		int level;
		int turnsToRegen;
		int invMaxSize = 20;
		vector<Item> inventory; //Not used yet
};

#endif
