#ifndef object
#define object

class Object
{
public:
	virtual char getSymbol()=0;
	virtual bool isEnemy()=0;
	virtual bool isWall() = 0;
	
};

#endif
