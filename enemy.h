#ifndef ENEMY_H
#define ENEMY_H

using namespace std;

class Player;

class Enemy
{
	public:
	
		Enemy();
		
		int getHealth();
		void setHealth(int x);
		int getSpeed();
		int getAttack();
		int getItem();
		int getDefense();
		
		void Attack(Player& target);
		void takeDamage(int damage);
		
	private:
		
		int health;
		int attack;
		int defense;
		int speed;
		int item;
};

#endif
