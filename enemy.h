#include "Object.h"

#ifndef ENEMY_H
#define ENEMY_H

using namespace std;


class Enemy: public Object
{
	public:
	
		Enemy(int, int);
		
		int getHealth();
		void setHealth(int x);
		void setType(int x);
		int getAttack();
		int getDefense();
		int getType();
		
		int getX();
		void setX(int);
		int getY();
		void setY(int);
		//void Attack(Player& target);
		void takeDamage(int damage);

		string getSymbol();
		void setExp(int exp);
		int getExp();
		bool isEnemy();
		bool isWall();
		bool isItem();
		bool isDoor();
		bool isExit();
		
	private:
		
		int health;
		int attack;
		int defense;
		int item;
		int type;
		int exp;
		int posX, posY;
};

#endif
