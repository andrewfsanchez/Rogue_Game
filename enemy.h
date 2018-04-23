#include "Object.h"

#ifndef ENEMY_H
#define ENEMY_H

using namespace std;


class Enemy: public Object
{
	public:
	
		Enemy();
		
		int getHealth();
		void setHealth(int x);
		void setType(int x);
		int getSpeed();
		int getAttack();
		int getDefense();
		int getType();
		
		//void Attack(Player& target);
		void takeDamage(int damage);

		string getSymbol();
		int getExperience(int type);
		bool isEnemy();
		bool isWall();
		bool isItem();
		bool isDoor();
		bool isExit();
		
	private:
		
		int health;
		int attack;
		int defense;
		int speed;
		int item;
		int type;
		
		int batExp;
		int spiderExp;
		int lizardExp;
		int zombieExp;
		int kingExp;
};

#endif
