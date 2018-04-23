#include "Object.h" 

#ifndef PLAYER_H
#define PLAYER_H

using namespace std;



class Player : public Object
{
	public:
		
		Player();
		int getHealth();
		void setHealth(int x);
		int getAttack();
		void setAttack(int x);
		int getDefense();
		void setDefense(int x);
		int getRegen();
		void setRegen(int x);
		
		int getMaxHealth();

		int getX();
		void setX(int);
		int getY();
		void setY(int);
		
		void regeneration();
		void levelUp();
		int getLevel();
		

		void takeDamage(int damage);
		void addExp(int);
		

		string getSymbol();
		bool isEnemy();
		bool isWall();
		bool isItem();
		bool isDoor();
		bool isExit();
		bool isPlayer();
	
	private:

		int x;
		int y;
		
		int maxHealth;
		int currentHealth;

		int attack;
		int defense;
		int regen;
		int level;
		int levelUpExp;
		int currentExp;
		int turnsToRegen;
		int invMaxSize = 20;
};

#endif
