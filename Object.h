#include <string>
#include <vector>
using namespace std;

#ifndef object
#define object

class Object
{
public:
	virtual string getSymbol() = 0;
	virtual bool isEnemy() = 0;
	virtual bool isWall() = 0;
	virtual bool isItem() = 0;
	virtual bool isDoor() = 0;
	virtual bool isExit() = 0;

	virtual int getHealth()
	{
		return 0;
	}
	virtual void setHealth(int)
	{
		return;
	}
	virtual void regeneration()
	{
		return;
	}
	virtual void takeDamage(int)
	{
		return;
	}
	virtual void setAttack(int)
	{
		return;
	}
	virtual int getAttack()
	{
		return 0;
	}
	virtual void setDefense(int)
	{
		return;
	}
	virtual int getDefense()
	{
		return 0;
	}

	virtual void setMaxHealth(int)
	{
		return;
	}
	virtual int getMaxHealth()
	{
		return 0;
	}
	virtual void setRegen(int)
	{
		return;
	}
	virtual int getRegen()
	{
		return 0;
	}
	virtual int getX()
	{
		return 0;
	}
	virtual int getY()
	{
		return 0;
	}
	virtual void setX(int)
	{
		return;
	}
	virtual void setY(int)
	{
		return;
	}
	virtual int getType()
	{
		return 0;
	}
	virtual void setType(int)
	{
		return;
	}
	virtual string getName()
	{
		return "";
	}
	virtual int getHealthMod()
	{
		return 0;
	}
	virtual int getDefenseMod()
	{
		return 0;
	}
	virtual int getAttackMod()
	{
		return 0;
	}
	virtual int getRegenMod()
	{
		return 0;
	}
	virtual bool isWeapon()
	{
		return false;
	}
	virtual bool isArmor()
	{
		return false;
	}
	virtual bool isConsumable()
	{
		return false;
	}
	virtual int getExperience()
	{
		return 0;
	}
	virtual void addExp(int)
	{
		return;
	}




	
};

#endif
