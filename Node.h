#include "Object.h"
#include <iostream>


#ifndef NODE
#define NODE

class Node
{
public:
	Node(Object* thing);
	Node();
	Object* getObject();
	void setObject(Object* thing);
	void print();

private:
	Object* space;

};


#endif 
