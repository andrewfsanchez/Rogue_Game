#include <string>
using namespace std;

#ifndef object
#define object

class Object
{
public:
	virtual string getSymbol()=0;
	virtual bool isEnemy()=0;
	virtual bool isWall() = 0;
	virtual bool isItem() = 0;
	virtual bool isDoor() = 0;
	
};

#endif
