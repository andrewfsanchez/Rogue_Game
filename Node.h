#include "Object.h"
#include <iostream>
#include "Object.h"

#ifndef NODE
#define NODE

class Node
{
public:
	Node(Object* thing);
	Object* getObject();
	void setObject(Object* thing);
	void print();

private:
	Object* space;

};


#endif 
