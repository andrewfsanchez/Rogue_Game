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
		int getAttack();
		int getDefense();
		int getType();
		void setX(int x);
		void setY(int y);
		int getX();
		int getY();
		
		//void Attack(Player& target);
		void takeDamage(int damage);

		string getSymbol();
		bool isEnemy();
		bool isWall();
		bool isItem();
		bool isDoor();
		
	private:
		
		int health;
		int attack;
		int defense;
		int item;
		int type;
		int x;
		int y;
};

#endif
